#include "TH1D.h"
#include "TTree.h"
#include "TFile.h"
#include "TROOT.h"
#include <random>
#include <sys/time.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

double clock_now()
{
    struct timeval now;

    gettimeofday(&now, NULL);
    return (double)now.tv_sec + (double)now.tv_usec/1.0e6;
}

void test_hist1() {
    TH1D* hi = new TH1D("my_hist", "My Hist", 10, -30.0, 30.0);
    int n = 100000000;
    for(int i=0;i<n; i++) {
        hi->Fill(random());
    }
    delete hi;
}

void test_hist2() {
    std::map<int, TH1D*> hm;
    for (int j=0;j<100;j++) {
        TH1D* hi = new TH1D(std::to_string(j).c_str(), "My Hist", 10*j, -30.0, 30.0);
        hm[j] = hi;
    }
    int n = 100000;
    for(int i=0;i<n; i++) {
        for (int j=0;j<100;j++) {
            hm[j]->Fill(random());
        }
    }
}

void test_hist3() {
    TH1D* hi = new TH1D("my_hist", "My Hist", 10, -30.0, 30.0);
    int n = 10000000;
    double ih = 0.0;
    for(int i=0;i<n; i++) {
        hi->Fill(random());
        ih = hi->Integral();
        ih += hi->GetRMS();
        ih += hi->GetMean();
    }
    delete hi;
}

void test_ttree1() {
    TFile* tf = new TFile("test.root", "RECREATE");
    TTree* ttree = new TTree("my_tree", "My Tree");

    double p1[1] = {0.0};
    int p2[1] = {0};
    float p3[1] = {0.0};

    ttree->Branch("p1", p1, "p1/D");
    ttree->Branch("p2", p2, "p2/I");
    ttree->Branch("p3", p3, "p3/F");
    
    for (int i=0; i<10000000; i++) {
        p1[0] = i;
        p2[0] = i*2;
        p3[0] = i*3;
        ttree->Fill();
    }
    tf->Write();
    tf->Close();
}

void test_ttree2() {
    TFile* tf = new TFile("test.root");
    TTree* ttree = (TTree*)(tf->Get("my_tree"));

    double p1[1] = {0.0};
    int p2[1] = {0};
    float p3[1] = {0.0};

    ttree->SetBranchAddress("p1", &p1);
    ttree->SetBranchAddress("p2", &p2);
    ttree->SetBranchAddress("p3", &p3);
    
    double s = 0.0;
    for (int i=0; i < ttree->GetEntries(); i++) {
        ttree->GetEntry(i);
        s += p1[0] + p2[0] + p3[0];
    }
    tf->Close();
}

double best(void (*f)(void) ) {
    std::vector<double> vs;
    for (int i=0; i<5; i++) {
        double t0 = clock_now();
        (*f)();
        double t1 = clock_now();
        vs.push_back(t1-t0);
    }
    double m = 0;
    for (auto& v : vs) {
        m += v;
    }
    return m / vs.size();
}

int main(int argc, const char** argv) {
    gROOT->ProcessLine("gErrorIgnoreLevel = 3001;");
    std::cout << "hist: " << best(&test_hist1) << std::endl;
    std::cout << "hist2: " << best(&test_hist2) << std::endl;
    std::cout << "hist3: " << best(&test_hist3) << std::endl;
    std::cout << "ttree1: " << best(&test_ttree1) << std::endl;
    std::cout << "ttree2: " << best(&test_ttree2) << std::endl;
}
