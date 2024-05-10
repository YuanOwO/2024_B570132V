#include <iomanip>
#include <iostream>
using namespace std;

class active_region {
  protected:
    double VBB, VCC, VBE, RB, RC, Beta;
    double IB, IC, IE, VCE;

  public:
    void input() { cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta; }

    void output() {
        cout << fixed << setprecision(2) << IC << " " << setprecision(2) << IB
             << " " << setprecision(2) << IE << " " << setprecision(2) << VCE
             << endl;
    }

    virtual void DC_analysis();
};

class saturation_region : public active_region {
  public:
    void DC_analysis();
};

void active_region::DC_analysis() {
    IB = (VBB - VBE) / RB;
    IC = Beta * IB;
    IE = (1 + Beta) * IB;
    VCE = VCC - IC * RC;
};

void saturation_region::DC_analysis() {
    VCE = 0.2;
    IC = (VCC - VCE) / RC;
    IB = (VBB - VBE) / RB;
    IE = IB + IC;
};

int main() {
    bool region;
    cin >> region;
    active_region *ptr =
        (region == true ? new active_region : new saturation_region);
    ptr->input();
    ptr->DC_analysis();
    ptr->output();
}
