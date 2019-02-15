#pragma once

#include "UHH2/core/include/Hists.h"
#include "UHH2/core/include/Event.h"

namespace uhh2examples {

/**  \brief Example class for booking and filling histograms
 * 
 * NOTE: This class uses the 'hist' method to retrieve histograms.
 * This requires a string lookup and is therefore slow if you have
 * many histograms. Therefore, it is recommended to use histogram
 * pointers as member data instead, like in 'common/include/ElectronHists.h'.
 */
class Plot94JetsHists: public uhh2::Hists {
public:
    // use the same constructor arguments as Hists for forwarding:
    Plot94JetsHists(uhh2::Context & ctx, const std::string & dirname);

    virtual void fill(const uhh2::Event & ev) override;
    virtual ~Plot94JetsHists();

  protected:
    uhh2::Event::Handle<std::vector <Jet>  > handleAK8Jets;
    uhh2::Event::Handle<std::vector <GenParticle>  > h_particles;
    TH2F *ratioAK4_weights;
    TH2F *ratioAK8_weights;
    bool isMC;
};

}
