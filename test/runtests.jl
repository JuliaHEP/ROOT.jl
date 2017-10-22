using ROOT
using Compat.Test

using Cxx


cxxinclude("TFile.h")
cxxinclude("TTree.h")
cxxinclude("TChain.h")

cxxinclude("TH1.h")
cxxinclude("TH1D.h")


@Base.Test.testset "Package ROOT" begin
    mktempdir() do scratchdir

        @testset "TTree and TChain" begin

            cd(scratchdir) do
                @test icxx"""
                    TFile output_file("testdata.root", "recreate");
                    auto tree = new TTree("data", "Data");
                    Int_t x = 0;
                    tree->Branch("x", &x);
                    for (size_t i = 1; i <= 10; ++i) {
                        x = 2 * i;
                        tree->Fill();
                    }
                    output_file.Write();
                    output_file.Close();
                    true;
                """

                @test icxx"""
                    TChain chain("data");
                    chain.AddFile("testdata.root");
                    Int_t x = 0;
                    chain.SetBranchAddress("x", &x);
                    auto n = chain.GetEntries();
                    Int_t s = 0;
                    for (size_t i = 0; i < n; ++i) {
                        chain.GetEntry(i);
                        s += x;
                    }
                    s;
                """ == 110
            end
        end

        @testset "TH1" begin
            @test icxx"""
                auto *hist = new TH1D("hist", "Hist", 10, 0, 10);
                for (Int_t i = 0; i < 10; ++i) hist->Fill(i);
                auto s = hist->Integral();
                delete hist;
                s;
            """ ≈ 10
        end

    end # mktempdir
end
