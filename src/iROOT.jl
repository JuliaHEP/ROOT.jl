function _event_loop()
    system = gSystem()
    while true
        ProcessEvents(system)
        sleep(0.01)
    end
end

function _init_event_loop()
    ROOT!EnableThreadSafety()
    Delete(TCanvas())
    SetBatch(ROOT!GetROOT(), false)
    schedule(Task(_event_loop))
    nothing
end
