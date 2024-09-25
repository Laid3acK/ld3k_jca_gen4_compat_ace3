class CfgPatches
{
    class ld3k_jca_gen4_compat_ace3
    {
        requiredAddons[]=
        {
            "Weapons_F_JCA_Gen4",
            "Weapons_F_JCA_Gen4_Accessories",
            "Weapons_F_JCA_gen4_Rifles_M4A1",
            "Weapons_F_JCA_gen4_Rifles_M4A4",
            "Weapons_F_JCA_gen4_Rifles_SR10",
            "Weapons_F_JCA_gen4_Rifles_SR25"
        };
        requiredversion=0.1;
        units[]={};
        weapons[]={};
    };
};
class CfgAmmo
{
    // JCA Bullets inherited from vanilla class B_556x45_Ball. To avoid all conflict with other mods, all JCA bullets with JCA as prefixe.
    // class B_556x45_Ball: BulletBase from official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class BulletBase;
    class JCA_B_556x45_Ball: BulletBase // ACE3 https://github.com/acemod/ACE3/blob/master/addons/ballistics/CfgAmmo.hpp#L117
    {
        ACE_caliber=5.70; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/223-rem-170406-en.pdf
        ACE_bulletLength=23.01;
        ACE_bulletMass=4.02;
        ACE_ammoTempMuzzleVelocityShifts[]={-27.20,-26.44,-23.76,-21.00,-17.54,-13.10,-7.95,-1.62,6.24,15.48,27.75}; // default ACE_ammoTempMuzzleVelocityShifts values. Muzzle velocity shift 0 at 70°F (21°C), -8m/s at 15°C
        ACE_ballisticCoefficients[]={0.151}; // ASM BC converted to ICAO 0.149012 for airFriction and dispersion calculation
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=7;
        // ACE_muzzleVelocities[]={723,764,796,825,843,866,878,892,906,915,922,900}; default ACE3 B_556x45_Ball
        ACE_muzzleVelocities[]={731,772,804,833,851,874,886,900,914,923,930,908}; // Muzzle Velocities shift +8m/s at 70°F (21°C) 917m/s 18.1" barrel (459.74mm), at 15°C 909m/s 18.1" barrel (459.74mm) according to JCA_30Rnd_556x45_PMAG and _Stanag initSpeed
        ACE_barrelLengths[]={210.82,238.76,269.24,299.72,330.2,360.68,391.16,419.1,449.58,480.06,508,609.6}; // M4A1 CQB, M4A4, M4A4 EGLM 11" (279.4mm) / M4A1, M4A1 EGLM 14.5" (368.3mm) 3D models' barrel lengths
        airLock=1;
        hit=9;
        indirectHit=0;
        indirectHitRange=0;
        cost=1;
        typicalSpeed=920;
        airFriction=-0.0013463; // ACE3 0.00130094, B_556x45_Ball 0.0012, airFrictionAnalysis.txt in docs folder
        waterFriction=-0.3;
        caliber=0.869565;
        model="\A3\Weapons_f\Data\bullettracer\tracer_white"; // B_762x51_Ball, B_556x45_Ball tracer_yellow
        tracerScale=1;
        tracerStartTime=0.17; // 140 m – ≥ 600 m typically 800 m, Strelok Pro MV 920m/s ICAO at 140m  ToF=0.17s, B_556x45_Ball 0.05, https://www.nammo.com/
        tracerEndTime=1.62; // 140 m – ≥ 600 m typically 800 m, Strelok Pro MV 920m/s ICAO at 800m  ToF=1.62s, B_556x45_Ball 1, https://www.nammo.com/
        nvgOnly=0; // B_556x45_Ball w/o nvgOnly
        audibleFire=35;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        aiAmmoUsageFlags=64;
        class CamShakeExplode
        {
            power=2.23607;
            duration=0.4;
            frequency=20;
            distance=6.7082;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };
    class JCA_B_556x45_Ball_Tracer_Red: JCA_B_556x45_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_556x45_Ball_Tracer_Green: JCA_B_556x45_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_556x45_Ball_Tracer_Yellow: JCA_B_556x45_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_JCA_B_556x45_Ball_Tracer_IR: JCA_B_556x45_Ball // JCA_JCA to avoid all conflict with other mods and RPT Updating base class. JCA default config: JCA_B_556x45_Ball_Tracer_IR: B_556x45_Ball
    {
        tracerScale=0.5; // IR dim tracer, B_556x45_Ball 1
        tracerStartTime=0.01; // 13 m-600 m (typically visible to 950 m), Strelok Pro MV 930m/s ICAO at 13m  ToF=0.01s, B_556x45_Ball 0.05, https://www.nammo.com/
        tracerEndTime=2.12; // 13 m-600 m (typically visible to 950 m), Strelok Pro MV 930m/s ICAO at 950m  ToF=2.12s, B_556x45_Ball 1, https://www.nammo.com/
        nvgOnly=1;
    };
    /*class B_556x45_dual: B_556x45_Ball // from official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        cartridge="FxCartridge_65";
        audibleFire=20;
        dangerRadiusBulletClose=4;
        dangerRadiusHit=8;
        suppressionRadiusBulletClose=2;
        suppressionRadiusHit=4;
        typicalSpeed=270;
        airFriction=-0.02;
        waterFriction=-0.01;
        effectFly="AmmoUnderwater";
        nvgOnly=1;
        aiAmmoUsageFlags="64 + 32";
    };*/
    class JCA_B_556x45_Ball_Dual: JCA_B_556x45_Ball // 5.56mm underwater subsonic DSG Technology https://dsgtec.com/ https://www.thefirearmblog.com/blog/2017/04/20/dsg-technology-underwater-ammo/
    {
        ACE_caliber=5.70; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/223-rem-170406-en.pdf
        ACE_bulletLength=23.01;
        ACE_bulletMass=4.02;
        // ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; default ACE3
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.151}; // ASM BC converted to ICAO 0.149012 for airFriction calculation
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ASM";
        ACE_dragModel=7;
        ACE_muzzleVelocities[]={248,268}; // muzzle velocities 248, 268 m/s at 21°C (70°F: Temp vs MV chart zero), 247, 267 m/s at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to M4A1/A4 initSpeed
        ACE_barrelLengths[]={279.4,368.3}; // M4A1 CQB, M4A4, M4A4 EGLM 11" (279.4mm) / M4A1, M4A1 EGLM 14.5" (368.3mm) 3D models' barrel lengths
        // cartridge="FxCartridge_65";
        visibleFire=1; // B_127x54_Ball, BulletBase 3
        audibleFire=5; // B_127x54_Ball, B_556x45_Ball 35, B_556x45_dual 20
        dangerRadiusBulletClose=4; // B_556x45_Ball 8
        dangerRadiusHit=8; // B_556x45_Ball 12
        suppressionRadiusBulletClose=2; // B_556x45_Ball 6
        suppressionRadiusHit=4; // B_556x45_Ball 8
        typicalSpeed=270;
        airFriction=-0.00056309; // airFrictionAnalysis.txt in docs folder, https://github.com/acemod/ACE3/pull/7982
        waterFriction=-0.01;
        effectFly="AmmoUnderwater";
        nvgOnly=1;
        aiAmmoUsageFlags="64 + 32";
    };
    // JCA Bullets inherited from vanilla class B_762x51_Ball. To avoid all conflict with other mods, all JCA bullets with JCA as prefixe
    // class B_762x51_Ball: BulletBase from official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    class JCA_B_762x51_Ball: BulletBase // ACE_762x51_Ball_Mk316_Mod_0
    {
        ACE_caliber=7.85; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/tabical-en-page125.pdf
        ACE_bulletLength=31.5; // Strelok Pro, Applied Ballistics
        ACE_bulletMass=11.34; // 175gr
        ACE_muzzleVelocityVariationSD=0.3; // ACE3 default value https://github.com/acemod/ACE3/blob/master/addons/advanced_ballistics/script_component.hpp#L32
        // ACE_ammoTempMuzzleVelocityShifts[]={-26.55,-25.47,-22.85,-20.12,-16.98,-12.80,-7.64,-1.53,5.96,15.17,26.19}; default ACE3
        // ACE_ammoTempMuzzleVelocityShifts[]={-5.3, -5.1, -4.6, -4.2, -3.4, -2.6, -1.4, -0.3, 1.4, 3.0, 5.2}; default ACE_762x51_Ball_Mk316_Mod_0
        ACE_ammoTempMuzzleVelocityShifts[]={-5.31,-5.094,-4.57,-4.024,-3.396,-2.56,-1.528,-0.306,1.192,3.034,5.238}; // default ACE_ammoTempMuzzleVelocityShifts values /5. Muzzle velocity shift 0 at 70°F (21°C), -2m/s at 15°C
        // ACE_ballisticCoefficients[]={0.243}; // Bryan Litz Applied Ballistics ICAO G7 BC based on Sierra ASM G1 BC 0.505, 2800 fps (853m/s) and above
        ACE_ballisticCoefficients[]={0.489}; // ICAO G1 BC 0.48947 converted from Sierra bullet 7.62mm 175 Gr. HPBT MatchKing ASM G1 BC 0.496 between 2800 fps (853m/s) and 1800 fps (549m/s) https://www.sierrabullets.com/product/30-cal-7-62mm-175-gr-hpbt-matchking/
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        // ACE_muzzleVelocities[]={775,790,805,810}; default ACE_762x51_Ball_Mk316_Mod_0
        // ACE_barrelLengths[]={406.4,508.0,609.6,660.4}; default ACE_762x51_Ball_Mk316_Mod_0
        ACE_muzzleVelocities[]={766,777,792,807,812}; // muzzle velocities 772 / 792 m/s at 21°C (70°F: Temp vs MV chart zero), 770 / 790 m/s at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_arifle_SR10 / SR25 initSpeed
        ACE_barrelLengths[]={330.2,406.4,508,609.6,660.4}; // SR10 14.5" (368.3mm) / SR25 20" (508mm) 3D models' barrel lengths
        hit=16; // ACE_762x51_Ball_Mk316_Mod_0, B_762x51_Ball 11.6
        indirectHit=0;
        indirectHitRange=0;
        cartridge="FxCartridge_762";
        visibleFire=3;
        audibleFire=45;
        dangerRadiusBulletClose=8;
        dangerRadiusHit=12;
        suppressionRadiusBulletClose=6;
        suppressionRadiusHit=8;
        cost=1.2;
        airLock=1;
        typicalSpeed=790; // ACE_762x51_Ball_Mk316_Mod_0, B_762x51_Ball 800
        caliber=1.8; // ACE_762x51_Ball_Mk316_Mod_0, B_762x51_Ball 1.6
        model="\A3\Weapons_f\Data\bullettracer\tracer_white";
        tracerScale=1.2; // ACE3, B_762x51_Ball 0.6
        tracerStartTime=0.19; // 140 m – ≥ 775 m typically 900 m, Strelok Pro ToF ICAO at 140m 0.19s, B_762x51_Ball 0.0075, https://www.nammo.com/
        tracerEndTime=1.72; // 140 m – ≥ 775 m typically 900 m, Strelok Pro ToF ICAO at 900m 1.72s, B_762x51_Ball 5, https://www.nammo.com/
        nvgOnly=0; // B_762x51_Ball w/o nvgOnly
        airFriction=-0.00084907; // ACE3 0.00084311, B_762x51_Ball 0.001, airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=2.8284299;
            duration=0.60000002;
            frequency=20;
            distance=8.48528;
        };
        class CamShakeHit
        {
            power=5;
            duration=0.2;
            frequency=20;
            distance=1;
        };
    };
    class JCA_B_762x51_Tracer_Red: JCA_B_762x51_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_red";
    };
    class JCA_B_762x51_Tracer_Green: JCA_B_762x51_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_green";
    };
    class JCA_B_762x51_Tracer_Yellow: JCA_B_762x51_Ball
    {
        model="\A3\Weapons_f\Data\bullettracer\tracer_yellow";
    };
    class JCA_JCA_B_762x51_Tracer_IR: JCA_B_762x51_Ball // JCA_JCA to avoid all conflict with other mods and RPT Updating base class. JCA default config: JCA_B_762x51_Tracer_IR: B_762x51_Ball
    {
        tracerScale=0.6; // IR dim tracer, B_762x51_Ball
        tracerStartTime=0.02; // 13–775 m (typically visible to 1250 m), Strelok Pro ToF ICAO at 13m 0.02s, B_762x51_Ball 0.0075, https://www.nammo.com/
        tracerEndTime=2.8; // 13–775 m (typically visible to 1250 m), Strelok Pro ToF ICAO at 1250m 2.80s, B_762x51_Ball 5, https://www.nammo.com/
        nvgOnly=1;
    };
    class JCA_B_762x51_Subsonic: JCA_B_762x51_Ball // Lapua subsonic B416, 325m/s 16" (406.4mm) barrel (Trajectory charts) https://www.lapua.com/product/308-win-subsonic-fmjbt-tactical-cartridge-13g-200gr-4317340/
    {
        ACE_caliber=7.85; // https://bobp.cip-bobp.org/uploads/tdcc/tab-i/tabical-en-page125.pdf
        ACE_bulletLength=34.11; // Strelok Pro
        ACE_bulletMass=12.96; // 200 gr
        ACE_ammoTempMuzzleVelocityShifts[]={-2.655,-2.547,-2.285,-2.012,-1.698,-1.280,-0.764,-0.153,0.596,1.517,2.619}; // default ACE_ammoTempMuzzleVelocityShifts values /10. Muzzle velocity shift 0 at 70°F (21°C), -1m/s at 15°C
        ACE_ballisticCoefficients[]={0.518}; // https://www.lapua.com/product/30-cal-fmjbt-subsonic-bullet-b416-130-g-200-gr/
        ACE_velocityBoundaries[]={};
        ACE_standardAtmosphere="ICAO";
        ACE_dragModel=1;
        ACE_muzzleVelocities[]={321,326,332,339,341}; // muzzle velocities 324 / 332 m/s at 21°C (70°F: Temp vs MV chart zero), 323 / 331 m/s at 15°C (ICAO: 15°C, 1013.25 hPa, 0%) according to JCA_arifle_SR10 / SR25 initSpeed
        ACE_barrelLengths[]={330.2,406.4,508,609.6,660.4}; // SR10 14.5" (368.3mm) / SR25 20" (508mm) 3D models' barrel lengths
        hit=6; // ACE_762x51_Ball_Subsonic, B_762x51_Ball 11.6
        visibleFire=1; // B_127x54_Ball, B_762x51_Ball 3
        audibleFire=5; // B_127x54_Ball, B_762x51_Ball 45
        dangerRadiusBulletClose=4; // B_127x54_Ball, B_762x51_Ball 8
        suppressionRadiusBulletClose=2; // B_127x54_Ball, B_762x51_Ball 6
        typicalSpeed=320; // ACE_762x51_Ball_Subsonic
        caliber=1; // ACE_762x51_Ball_Subsonic, B_762x51_Ball 1.6
        airFriction=-0.00049496; // ACE3 0.00060194, B_762x51_Ball 0.001, airFrictionAnalysis.txt in docs folder
        class CamShakeExplode
        {
            power=2.23607; // B_127x54_Ball, B_762x51_Ball 2.8284299
            duration=0.4; // B_127x54_Ball, B_762x51_Ball 0.6
            frequency=20; // B_127x54_Ball ,B_762x51_Ball 20
            distance=6.7082; // B_127x54_Ball, B_762x51_Ball 8.48528
        };
    };
};
class CfgMagazines
{
    class CA_Magazine;
    class JCA_20Rnd_762x51_PMAG: CA_Magazine
    {
        ammo="JCA_B_762x51_Ball";
        mass=14.7; //  PMAGs SR25 20 rnds 5.7oz (162g) + 20x 25.3g, JCA 9 https://magpul.com/pmag20lr-srgenm3-7-62x51.html?mp_global_color=118
        initSpeed=790; // 7.62x51 Mk316 Mod0, according to ACE_muzzleVelocities 20" barrel (508mm) ICAO conditions (15°C, 1013.25hPa, 0%), 20Rnd_762x51_Mag 850
    };
    class JCA_20Rnd_762x51_Red_PMAG: JCA_20Rnd_762x51_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
    };
    class JCA_20Rnd_762x51_Green_PMAG: JCA_20Rnd_762x51_Red_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Yellow_PMAG: JCA_20Rnd_762x51_Red_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_IR_PMAG: JCA_20Rnd_762x51_Red_PMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
    };
    class JCA_20Rnd_762x51_Tracer_Red_PMAG: JCA_20Rnd_762x51_Red_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_20Rnd_762x51_Tracer_Green_PMAG: JCA_20Rnd_762x51_Tracer_Red_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Tracer_Yellow_PMAG: JCA_20Rnd_762x51_Tracer_Red_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_Tracer_IR_PMAG: JCA_20Rnd_762x51_Tracer_Red_PMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_20Rnd_762x51_Subsonic_PMAG: JCA_20Rnd_762x51_PMAG
    {
        author="Grave";
        displayName="7.62 mm 20Rnd Subsonic PMAG";
        ammo="JCA_B_762x51_Subsonic";
        displaynameshort="Subsonic";
        initSpeed=331; // according to ACE_muzzleVelocities 20" barrel (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_20Rnd_762x51_Sand_PMAG: JCA_20Rnd_762x51_PMAG
    {
    };
    class JCA_20Rnd_762x51_Red_Sand_PMAG: JCA_20Rnd_762x51_Sand_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
    };
    class JCA_20Rnd_762x51_Green_Sand_PMAG: JCA_20Rnd_762x51_Red_Sand_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Yellow_Sand_PMAG: JCA_20Rnd_762x51_Red_Sand_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_IR_Sand_PMAG: JCA_20Rnd_762x51_Red_Sand_PMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
    };
    class JCA_20Rnd_762x51_Tracer_Red_Sand_PMAG: JCA_20Rnd_762x51_Red_Sand_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_20Rnd_762x51_Tracer_Green_Sand_PMAG: JCA_20Rnd_762x51_Tracer_Red_Sand_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Tracer_Yellow_Sand_PMAG: JCA_20Rnd_762x51_Tracer_Red_Sand_PMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_Tracer_IR_Sand_PMAG: JCA_20Rnd_762x51_Tracer_Red_Sand_PMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_20Rnd_762x51_Subsonic_Sand_PMAG: JCA_20Rnd_762x51_Sand_PMAG
    {
        author="Grave";
        displayName="7.62 mm 20Rnd Subsonic Sand PMAG";
        ammo="JCA_B_762x51_Subsonic";
        displaynameshort="Subsonic";
        initSpeed=331; // according to ACE_muzzleVelocities 20" barrel (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_20Rnd_762x51_SMAG: CA_Magazine
    {
        ammo="JCA_B_762x51_Ball";
        mass=15.7; //  SMAGs SR25 20 rnds 206g + 20x 25.3g, JCA 9
        initSpeed=790; // 7.62x51 Mk316 Mod0, according to ACE_muzzleVelocities 20" barrel (508mm) ICAO conditions (15°C, 1013.25hPa, 0%), 20Rnd_762x51_Mag 850
    };
    class JCA_20Rnd_762x51_Red_SMAG: JCA_20Rnd_762x51_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
    };
    class JCA_20Rnd_762x51_Green_SMAG: JCA_20Rnd_762x51_Red_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Yellow_SMAG: JCA_20Rnd_762x51_Red_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_IR_SMAG: JCA_20Rnd_762x51_Red_SMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
    };
    class JCA_20Rnd_762x51_Tracer_Red_SMAG: JCA_20Rnd_762x51_Red_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_20Rnd_762x51_Tracer_Green_SMAG: JCA_20Rnd_762x51_Tracer_Red_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Tracer_Yellow_SMAG: JCA_20Rnd_762x51_Tracer_Red_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_Tracer_IR_SMAG: JCA_20Rnd_762x51_Tracer_Red_SMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_20Rnd_762x51_Subsonic_SMAG: JCA_20Rnd_762x51_SMAG
    {
        author="Grave";
        displayName="7.62 mm 20Rnd Subsonic Mag";
        ammo="JCA_B_762x51_Subsonic";
        displaynameshort="Subsonic";
        initSpeed=331; // according to ACE_muzzleVelocities 20" barrel (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_20Rnd_762x51_Sand_SMAG: JCA_20Rnd_762x51_SMAG
    {
    };
    class JCA_20Rnd_762x51_Red_Sand_SMAG: JCA_20Rnd_762x51_Sand_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
    };
    class JCA_20Rnd_762x51_Green_Sand_SMAG: JCA_20Rnd_762x51_Red_Sand_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Yellow_Sand_SMAG: JCA_20Rnd_762x51_Red_Sand_SMAG
    {
        ammo="B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_IR_Sand_SMAG: JCA_20Rnd_762x51_Red_Sand_SMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
    };
    class JCA_20Rnd_762x51_Tracer_Red_Sand_SMAG: JCA_20Rnd_762x51_Red_Sand_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_20Rnd_762x51_Tracer_Green_Sand_SMAG: JCA_20Rnd_762x51_Tracer_Red_Sand_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Green";
    };
    class JCA_20Rnd_762x51_Tracer_Yellow_Sand_SMAG: JCA_20Rnd_762x51_Tracer_Red_Sand_SMAG
    {
        ammo="JCA_B_762x51_Tracer_Yellow";
    };
    class JCA_20Rnd_762x51_Tracer_IR_Sand_SMAG: JCA_20Rnd_762x51_Tracer_Red_Sand_SMAG
    {
        ammo="JCA_JCA_B_762x51_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_20Rnd_762x51_Subsonic_Sand_SMAG: JCA_20Rnd_762x51_Sand_SMAG
    {
        author="Grave";
        displayName="7.62 mm 20Rnd Subsonic Sand Mag";
        ammo="JCA_B_762x51_Subsonic";
        displaynameshort="Subsonic";
        initSpeed=331; // according to ACE_muzzleVelocities 20" barrel (508mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_30Rnd_556x45_PMAG: CA_Magazine // JCA default config
    {
        picture="\weapons_f_JCA_Gen4\MagazineProxies\data\UI\Icon_30Rnd_556x45_PMAG_CA.paa";
        author="Grave";
        scope=2;
        displayName="5.56 mm 30Rnd PMAG";
        ammo="JCA_B_556x45_Ball";
        count=30;
        mass=11.2; // Polymer magazine 30 rounds (empty) 140g + 30*12.3g (M855 cartridge weight)
        initSpeed=909; // according to ACE_muzzleVelocities 18.1" barrel (459.74mm) ICAO conditions (15°C, 1013.25hPa, 0%), ACE3 909, 30Rnd_556x45_Stanag 920
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="Caliber: 5.56x45 mm<br />Rounds: 30<br />Used in: 5.56 STANAG Rifles";
        modelSpecial="weapons_f_JCA_Gen4\MagazineProxies\30Rnd_556_PMAG.p3d";
        modelSpecialIsProxy=1;
        hiddenSelections[]=
        {
            "Camo"
        };
        hiddenSelectionsTextures[]=
        {
            "weapons_f_JCA_Gen4\MagazineProxies\data\mag_30Rnd_556_PMAG_black_CO.paa"
        };
    };
    class JCA_30Rnd_556x45_UW_PMAG: JCA_30Rnd_556x45_PMAG // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Dual Purpose PMAG";
        ammo="JCA_B_556x45_Ball_Dual";
        displaynameshort="UW";
        initSpeed=279; // according to M4A1/A4 initSpeed and ACE_muzzleVelocities M4A1 CQB, M4A4, M4A4 EGLM 11" (279.4mm) / M4A1, M4A1 EGLM 14.5" (368.3mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_30Rnd_556x45_Red_PMAG: JCA_30Rnd_556x45_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Red";
    };
    class JCA_30Rnd_556x45_Green_PMAG: JCA_30Rnd_556x45_Red_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Yellow_PMAG: JCA_30Rnd_556x45_Red_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_IR_PMAG: JCA_30Rnd_556x45_Red_PMAG
    {
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
    };
    class JCA_30Rnd_556x45_Tracer_Red_PMAG: JCA_30Rnd_556x45_Red_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_556x45_Tracer_Green_PMAG: JCA_30Rnd_556x45_Tracer_Red_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Tracer_Yellow_PMAG: JCA_30Rnd_556x45_Tracer_Red_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Tracer_IR_PMAG: JCA_30Rnd_556x45_Tracer_Red_PMAG
    {
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_30Rnd_556x45_sand_PMAG: JCA_30Rnd_556x45_PMAG
    {
    };
    class JCA_30Rnd_556x45_UW_sand_PMAG: JCA_30Rnd_556x45_sand_PMAG // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Dual Purpose Sand PMAG";
        ammo="JCA_B_556x45_Ball_Dual";
        displaynameshort="UW";
        initSpeed=279; // according to M4A1/A4 initSpeed and ACE_muzzleVelocities M4A1 CQB, M4A4, M4A4 EGLM 11" (279.4mm) / M4A1, M4A1 EGLM 14.5" (368.3mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_30Rnd_556x45_Red_sand_PMAG: JCA_30Rnd_556x45_sand_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Red";
    };
    class JCA_30Rnd_556x45_Green_sand_PMAG: JCA_30Rnd_556x45_Red_sand_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Yellow_sand_PMAG: JCA_30Rnd_556x45_Red_sand_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_IR_sand_PMAG: JCA_30Rnd_556x45_Red_sand_PMAG
    {
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
    };
    class JCA_30Rnd_556x45_Tracer_Red_sand_PMAG: JCA_30Rnd_556x45_Red_sand_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_556x45_Tracer_Green_sand_PMAG: JCA_30Rnd_556x45_Tracer_Red_sand_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG: JCA_30Rnd_556x45_Tracer_Red_sand_PMAG
    {
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Tracer_IR_sand_PMAG: JCA_30Rnd_556x45_Tracer_Red_sand_PMAG
    {
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    // JCA 5.56x45 Stanag Magazines use vanilla class 30Rnd_556x45_Stanag. To avoid all conflict with other mods and RPT Updating base class, all JCA 5.56x45 Stanag Magazines with JCA as prefixe
    /*class 30Rnd_556x45_Stanag: CA_Magazine from official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
    {
        picture="\a3\Weapons_F\MagazineProxies\data\UI\icon_30Rnd_556x45_Stanag_CA.paa";
        author="$STR_A3_Bohemia_Interactive";
        scope=2;
        displayName="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag0";
        ammo="B_556x45_Ball";
        count=30;
        initSpeed=920;
        tracersEvery=0;
        lastRoundsTracer=4;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag1";
        modelSpecial="\a3\Weapons_F_Exp\MagazineProxies\mag_556x45_stanag_30rnd.p3d";
        modelSpecialIsProxy=1;
    };
    class 30Rnd_556x45_Stanag: CA_Magazine // JCA default config
    {
        author="Grave";
        scope=2;
        displayName="5.56 mm 30Rnd Mag";
        picture="\weapons_f_JCA_Gen4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_CA.paa";
        modelSpecial="weapons_f_JCA_Gen4\MagazineProxies\30Rnd_556_SMAG.p3d";
        modelSpecialIsProxy=1;
        ammo="B_556x45_Ball";
        count=30;
        mass=8;
        initSpeed=920;
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag1";
    };*/
    class JCA_30Rnd_556x45_Stanag: CA_Magazine // JCA default config with JCA as prefixe
    {
        picture="\weapons_f_JCA_Gen4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_CA.paa";
        author="Grave";
        scope=2;
        displayName="5.56 mm 30Rnd Mag";
        ammo="JCA_B_556x45_Ball";
        count=30;
        mass=13.6; // Steel magazine 30 rounds (empty) 250g + 30*12.3g (M855 cartridge weight)
        initSpeed=909; // according to ACE_muzzleVelocities 18.1" barrel (459.74mm) ICAO conditions (15°C, 1013.25hPa, 0%), ACE3 909, 30Rnd_556x45_Stanag 920
        tracersEvery=0;
        lastRoundsTracer=0;
        descriptionShort="$STR_A3_CfgMagazines_30Rnd_556x45_Stanag1";
        modelSpecial="weapons_f_JCA_Gen4\MagazineProxies\30Rnd_556_SMAG.p3d";
        modelSpecialIsProxy=1;
    };
    class JCA_30Rnd_556x45_Stanag_UW: JCA_30Rnd_556x45_Stanag // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Dual Purpose Mag";
        ammo="JCA_B_556x45_Ball_Dual";
        displaynameshort="UW";
        initSpeed=279; // according to M4A1/A4 initSpeed and ACE_muzzleVelocities M4A1 CQB, M4A4, M4A4 EGLM 11" (279.4mm) / M4A1, M4A1 EGLM 14.5" (368.3mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_30Rnd_556x45_Stanag_Red: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Red) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_556x45_Stanag_Green: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Green) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Yellow: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Yellow) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_IR: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (IR) Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Red: JCA_30Rnd_556x45_Stanag_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Red) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Green: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Green) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_Yellow: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Yellow) Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Tracer_IR: JCA_30Rnd_556x45_Stanag_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (IR) Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
    class JCA_30Rnd_556x45_Stanag_Sand: JCA_30Rnd_556x45_Stanag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Sand Mag";
        picture="\weapons_f_JCA_Gen4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_sand_CA.paa";
        hiddenSelections[]=
        {
            "Camo"
        };
        hiddenSelectionsTextures[]=
        {
            "weapons_f_JCA_Gen4\MagazineProxies\data\mag_30Rnd_556_SMAG_sand_CO.paa"
        };
    };
    class JCA_30Rnd_556x45_Stanag_Sand_UW: JCA_30Rnd_556x45_Stanag_Sand // default Arma3 20Rnd_556x45_UW_mag
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Dual Purpose Sand Mag";
        ammo="JCA_B_556x45_Ball_Dual";
        displaynameshort="UW";
        initSpeed=279; // according to M4A1/A4 initSpeed and ACE_muzzleVelocities M4A1 CQB, M4A4, M4A4 EGLM 11" (279.4mm) / M4A1, M4A1 EGLM 14.5" (368.3mm) ICAO conditions (15°C, 1013.25hPa, 0%)
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Red: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Red) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        lastRoundsTracer=4;
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Green: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Green) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Yellow: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (Yellow) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_IR: JCA_30Rnd_556x45_Stanag_Sand_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Reload Tracer (IR) Sand Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red: JCA_30Rnd_556x45_Stanag_Sand
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Red) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Red";
        tracersEvery=1;
        displaynameshort="Tracer";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Green) Sand Mag";
        // picture="\weapons_f_JCA_Gen4\MagazineProxies\data\UI\Icon_30Rnd_556x45_SMAG_sand_CA.paa";
        ammo="JCA_B_556x45_Ball_Tracer_Green";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (Yellow) Sand Mag";
        ammo="JCA_B_556x45_Ball_Tracer_Yellow";
    };
    class JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR: JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red
    {
        author="Grave";
        displayName="5.56 mm 30Rnd Tracer (IR) Sand Mag";
        ammo="JCA_JCA_B_556x45_Ball_Tracer_IR";
        displaynameshort="Tracer IR";
    };
};
class CfgMagazineWells
{
    class STANAG_556x45
    {
        BI_Magazines[]= // JCA default config with 5.56x45mm JCA Mags
        /*{
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag_Red",
            "30Rnd_556x45_Stanag_Green",
            "30Rnd_556x45_Stanag_Yellow",
            "30Rnd_556x45_Stanag_IR",
            "30Rnd_556x45_Stanag_Tracer_Red",
            "30Rnd_556x45_Stanag_Tracer_Green",
            "30Rnd_556x45_Stanag_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Tracer_IR",
            "30Rnd_556x45_Stanag_Sand",
            "30Rnd_556x45_Stanag_Sand_Red",
            "30Rnd_556x45_Stanag_Sand_Green",
            "30Rnd_556x45_Stanag_Sand_Yellow",
            "30Rnd_556x45_Stanag_Sand_IR",
            "30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Sand_Tracer_IR"
        };*/
        { // 5.56x45mm default Arma3 Mags from official BI tool All-in-one Config Arma3 2.17.151913 https://community.bistudio.com/wiki/Arma:_All-in-one_Config
            "30Rnd_556x45_Stanag",
            "30Rnd_556x45_Stanag_green",
            "30Rnd_556x45_Stanag_red",
            "30Rnd_556x45_Stanag_Tracer_Red",
            "30Rnd_556x45_Stanag_Tracer_Green",
            "30Rnd_556x45_Stanag_Tracer_Yellow",
            "30Rnd_556x45_Stanag_Sand",
            "30Rnd_556x45_Stanag_Sand_green",
            "30Rnd_556x45_Stanag_Sand_red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "30Rnd_556x45_Stanag_Sand_Tracer_Yellow"
        };
        JCA_Magazines[]= // Weapon initSpeed -1 with ACE_barrelLength 459.74mm (18.1"), 909m/s at ICAO standart conditions (15°C, 1013.25 hPa, 0%) according to JCA_30Rnd_556x45 magazines and ACE3 30Rnd_556x45_Stanag initSpeed
        { // All 5.56x45mm JCA Mags
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW"
        };
    };
    class JCA_SR_762x51
    {
        JCA_Magazines[]= // Weapon initSpeed -1 with ACE_barrelLength 508mm (20"), 790m/s at ICAO standart conditions (15°C, 1013.25 hPa, 0%) according to JCA_20Rnd_762x51 magazines and ACE3 ACE_10Rnd_762x51_Mk316_Mod_0_Mag initSpeed
        {
            "JCA_20Rnd_762x51_PMAG",
            "JCA_20Rnd_762x51_Red_PMAG",
            "JCA_20Rnd_762x51_Green_PMAG",
            "JCA_20Rnd_762x51_Yellow_PMAG",
            "JCA_20Rnd_762x51_IR_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_PMAG",
            "JCA_20Rnd_762x51_Subsonic_PMAG",
            "JCA_20Rnd_762x51_sand_PMAG",
            "JCA_20Rnd_762x51_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_PMAG",
            "JCA_20Rnd_762x51_SMAG",
            "JCA_20Rnd_762x51_Red_SMAG",
            "JCA_20Rnd_762x51_Green_SMAG",
            "JCA_20Rnd_762x51_Yellow_SMAG",
            "JCA_20Rnd_762x51_IR_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_SMAG",
            "JCA_20Rnd_762x51_Subsonic_SMAG",
            "JCA_20Rnd_762x51_sand_SMAG",
            "JCA_20Rnd_762x51_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_SMAG"
        };
    };
};
class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons
{
    class InventoryMuzzleItem_Base_F;
    class InventoryOpticsItem_Base_F;
    class InventoryUnderItem_Base_F;
    class ItemCore;
    class Rifle;
    class Rifle_Base_F: Rifle
    {
        class WeaponSlotsInfo;
    };
    class JCA_arifle_M4A1_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=177.8; // 1:7"
        ACE_barrelLength=368.3; // 14.5" 3D model barrel length
        ACE_railHeightAboveBore=2.42081; // from ACE3 checkScopes.sqf
        initSpeed=-0.955996; // 869m/s - 267m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 880
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=63.6; // https://fnamerica.com/products/rifles/fn-m4a1/ (2885g), JCA 75
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.000543; // 3.32 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00058 (1.99 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.000543; // 3.32 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00058 (1.99 MOA)
        };
    };
    class JCA_arifle_M4A1_GL_base_F: JCA_arifle_M4A1_base_F
    {
        ACE_barrelLength=368.3; // 14.5" 3D model barrel length
        initSpeed=-0.955996; //  // 869m/s - 267m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=91.6; // H&K GLM 1270g https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/40%20mm%20systems/GLM, JCA 95
        };
    };
    class JCA_arifle_M4A1_short_base_F: JCA_arifle_M4A1_base_F
    {
        ACE_barrelLength=279.4; // 11" 3D model barrel length
        initSpeed=-0.886689; // 806m/s - 247m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=56.9; // Estimation based on HK416 variants https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/Assault%20rifles/HK416, JCA 60
        };
        class Single: Single
        {
            dispersion=0.000615; // 3.76 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00073 (2.51 MOA)
        };
        class FullAuto: FullAuto
        {
            dispersion=0.000615; // 3.76 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00073 (2.51 MOA)
        };
    };
    class JCA_arifle_M4A1_sand_F: JCA_arifle_M4A1_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG"
        };
    };
    class JCA_arifle_M4A1_GL_sand_F: JCA_arifle_M4A1_GL_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG"
        };
    };
    class JCA_arifle_M4A1_short_sand_F: JCA_arifle_M4A1_short_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG"
        };
    };
    class JCA_arifle_M4A4_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=177.8; // 1:7"
        ACE_barrelLength=279.4; // 11" 3D model barrel length
        ACE_railHeightAboveBore=2.42081; // from ACE3 checkScopes.sqf
        initSpeed=-0.886689; // 806m/s - 247m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 880
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=56.9; // Estimation based on HK416 variants https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/Assault%20rifles/HK416, JCA 60
        };
        class Single: Mode_SemiAuto
        {
            dispersion=0.000615; // 3.76 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00058 (1.99 MOA)
        };
        class FullAuto: Mode_FullAuto
        {
            dispersion=0.000615; // 3.76 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00058 (1.99 MOA)
        };
    };
    class JCA_arifle_M4A4_AFG_base_F: JCA_arifle_M4A4_base_F
    {
    };
    class JCA_arifle_M4A4_VFG_base_F: JCA_arifle_M4A4_base_F
    {
    };
    class JCA_arifle_M4A4_GL_base_F: JCA_arifle_M4A4_base_F
    {
        ACE_barrelLength=279.4; // 11" 3D model barrel length
        initSpeed=-0.886689; // 806m/s - 247m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 800
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=85.9; // H&K GLM 1270g https://www.heckler-koch.com/en/Products/Military%20and%20Law%20Enforcement/40%20mm%20systems/GLM, JCA 80
        };
    };
    class JCA_arifle_M4A4_AFG_sand_F: JCA_arifle_M4A4_AFG_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_M4A4_VFG_sand_F: JCA_arifle_M4A4_VFG_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_M4A4_GL_sand_F: JCA_arifle_M4A4_GL_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_30Rnd_556x45_Red_sand_PMAG",
            "JCA_30Rnd_556x45_sand_PMAG",
            "JCA_30Rnd_556x45_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_IR_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_sand_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_sand_PMAG",
            "JCA_30Rnd_556x45_UW_sand_PMAG",
            "JCA_30Rnd_556x45_PMAG",
            "JCA_30Rnd_556x45_Red_PMAG",
            "JCA_30Rnd_556x45_Green_PMAG",
            "JCA_30Rnd_556x45_Yellow_PMAG",
            "JCA_30Rnd_556x45_IR_PMAG",
            "JCA_30Rnd_556x45_Tracer_Red_PMAG",
            "JCA_30Rnd_556x45_Tracer_Green_PMAG",
            "JCA_30Rnd_556x45_Tracer_Yellow_PMAG",
            "JCA_30Rnd_556x45_Tracer_IR_PMAG",
            "JCA_30Rnd_556x45_UW_PMAG",
            "JCA_30Rnd_556x45_Stanag_Sand",
            "JCA_30Rnd_556x45_Stanag_Sand_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Sand_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_Sand_UW",
            "JCA_30Rnd_556x45_Stanag",
            "JCA_30Rnd_556x45_Stanag_Red",
            "JCA_30Rnd_556x45_Stanag_Green",
            "JCA_30Rnd_556x45_Stanag_Yellow",
            "JCA_30Rnd_556x45_Stanag_IR",
            "JCA_30Rnd_556x45_Stanag_Tracer_Red",
            "JCA_30Rnd_556x45_Stanag_Tracer_Green",
            "JCA_30Rnd_556x45_Stanag_Tracer_Yellow",
            "JCA_30Rnd_556x45_Stanag_Tracer_IR",
            "JCA_30Rnd_556x45_Stanag_UW"
        };
    };
    class JCA_arifle_SR25_base_F: Rifle_Base_F // https://en.wikipedia.org/wiki/SR-25
    {
        ACE_barrelTwist=285.75; // 1:11.25"
        ACE_barrelLength=508; // 20" 3D model barrel length
        ACE_railHeightAboveBore=2.4188499; // from ACE3 checkScopes.sqf
        initSpeed=-1; // 790m/s - 331m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 715
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_20Rnd_762x51_SMAG",
            "JCA_20Rnd_762x51_Red_SMAG",
            "JCA_20Rnd_762x51_Green_SMAG",
            "JCA_20Rnd_762x51_Yellow_SMAG",
            "JCA_20Rnd_762x51_IR_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_SMAG",
            "JCA_20Rnd_762x51_Subsonic_SMAG",
            "JCA_20Rnd_762x51_sand_SMAG",
            "JCA_20Rnd_762x51_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_SMAG",
            "JCA_20Rnd_762x51_PMAG",
            "JCA_20Rnd_762x51_Red_PMAG",
            "JCA_20Rnd_762x51_Green_PMAG",
            "JCA_20Rnd_762x51_Yellow_PMAG",
            "JCA_20Rnd_762x51_IR_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_PMAG",
            "JCA_20Rnd_762x51_Subsonic_PMAG",
            "JCA_20Rnd_762x51_sand_PMAG",
            "JCA_20Rnd_762x51_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_PMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=153; // empty weight 15.3 lb (6.9 kg), JCA 138
        };
        class single: Mode_SemiAuto
        {
            dispersion=0.000222; // 1.36 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00066 (2.27 MOA)
        };
    };
    class JCA_arifle_SR25_sand_F: JCA_arifle_SR25_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_20Rnd_762x51_sand_SMAG",
            "JCA_20Rnd_762x51_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_SMAG",
            "JCA_20Rnd_762x51_SMAG",
            "JCA_20Rnd_762x51_Red_SMAG",
            "JCA_20Rnd_762x51_Green_SMAG",
            "JCA_20Rnd_762x51_Yellow_SMAG",
            "JCA_20Rnd_762x51_IR_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_SMAG",
            "JCA_20Rnd_762x51_Subsonic_SMAG",
            "JCA_20Rnd_762x51_sand_PMAG",
            "JCA_20Rnd_762x51_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_PMAG",
            "JCA_20Rnd_762x51_PMAG",
            "JCA_20Rnd_762x51_Red_PMAG",
            "JCA_20Rnd_762x51_Green_PMAG",
            "JCA_20Rnd_762x51_Yellow_PMAG",
            "JCA_20Rnd_762x51_IR_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_PMAG",
            "JCA_20Rnd_762x51_Subsonic_PMAG"
        };
    };
    class JCA_arifle_SR10_base_F: Rifle_Base_F
    {
        ACE_barrelTwist=254; // 1:10"
        ACE_barrelLength=368.3; // 14.5" 3D model barrel length
        ACE_railHeightAboveBore=2.39586;
        initSpeed=-0.974684; // 770m/s - 323m/s according to ACE_muzzleVelocities at ICAO conditions (15°C, 1013.25hPa, 0%), JCA 715
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_20Rnd_762x51_PMAG",
            "JCA_20Rnd_762x51_Red_PMAG",
            "JCA_20Rnd_762x51_Green_PMAG",
            "JCA_20Rnd_762x51_Yellow_PMAG",
            "JCA_20Rnd_762x51_IR_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_PMAG",
            "JCA_20Rnd_762x51_Subsonic_PMAG",
            "JCA_20Rnd_762x51_sand_PMAG",
            "JCA_20Rnd_762x51_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_PMAG",
            "JCA_20Rnd_762x51_SMAG",
            "JCA_20Rnd_762x51_Red_SMAG",
            "JCA_20Rnd_762x51_Green_SMAG",
            "JCA_20Rnd_762x51_Yellow_SMAG",
            "JCA_20Rnd_762x51_IR_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_SMAG",
            "JCA_20Rnd_762x51_Subsonic_SMAG",
            "JCA_20Rnd_762x51_sand_SMAG",
            "JCA_20Rnd_762x51_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_SMAG"
        };
        class WeaponSlotsInfo: WeaponSlotsInfo
        {
            mass=120; // JCA (5.44 kg)
        };
        class single: Mode_SemiAuto
        {
            dispersion=0.000389; // 2.38 MOA (*0.562*0.000291), 0.562 value from https://github.com/acemod/ACE3/pull/5755, JCA 0.00066 (2.27 MOA)
        };
    };
    class JCA_arifle_SR10_AFG_base_F: JCA_arifle_SR10_base_F
    {
    };
    class JCA_arifle_SR10_VFG_base_F: JCA_arifle_SR10_base_F
    {
    };
    class JCA_arifle_SR10_AFG_sand_F: JCA_arifle_SR10_AFG_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_20Rnd_762x51_sand_PMAG",
            "JCA_20Rnd_762x51_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_PMAG",
            "JCA_20Rnd_762x51_PMAG",
            "JCA_20Rnd_762x51_Red_PMAG",
            "JCA_20Rnd_762x51_Green_PMAG",
            "JCA_20Rnd_762x51_Yellow_PMAG",
            "JCA_20Rnd_762x51_IR_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_PMAG",
            "JCA_20Rnd_762x51_Subsonic_PMAG",
            "JCA_20Rnd_762x51_sand_SMAG",
            "JCA_20Rnd_762x51_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_SMAG",
            "JCA_20Rnd_762x51_SMAG",
            "JCA_20Rnd_762x51_Red_SMAG",
            "JCA_20Rnd_762x51_Green_SMAG",
            "JCA_20Rnd_762x51_Yellow_SMAG",
            "JCA_20Rnd_762x51_IR_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_SMAG",
            "JCA_20Rnd_762x51_Subsonic_SMAG"
        };
    };
    class JCA_arifle_SR10_VFG_sand_F: JCA_arifle_SR10_VFG_base_F
    {
        magazines[]=
        { // Priority to JCA magazines first
            "JCA_20Rnd_762x51_sand_PMAG",
            "JCA_20Rnd_762x51_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_PMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_PMAG",
            "JCA_20Rnd_762x51_PMAG",
            "JCA_20Rnd_762x51_Red_PMAG",
            "JCA_20Rnd_762x51_Green_PMAG",
            "JCA_20Rnd_762x51_Yellow_PMAG",
            "JCA_20Rnd_762x51_IR_PMAG",
            "JCA_20Rnd_762x51_Tracer_Red_PMAG",
            "JCA_20Rnd_762x51_Tracer_Green_PMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_PMAG",
            "JCA_20Rnd_762x51_Tracer_IR_PMAG",
            "JCA_20Rnd_762x51_Subsonic_PMAG",
            "JCA_20Rnd_762x51_sand_SMAG",
            "JCA_20Rnd_762x51_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_sand_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_sand_SMAG",
            "JCA_20Rnd_762x51_Subsonic_sand_SMAG",
            "JCA_20Rnd_762x51_SMAG",
            "JCA_20Rnd_762x51_Red_SMAG",
            "JCA_20Rnd_762x51_Green_SMAG",
            "JCA_20Rnd_762x51_Yellow_SMAG",
            "JCA_20Rnd_762x51_IR_SMAG",
            "JCA_20Rnd_762x51_Tracer_Red_SMAG",
            "JCA_20Rnd_762x51_Tracer_Green_SMAG",
            "JCA_20Rnd_762x51_Tracer_Yellow_SMAG",
            "JCA_20Rnd_762x51_Tracer_IR_SMAG",
            "JCA_20Rnd_762x51_Subsonic_SMAG"
        };
    };
    class JCA_optic_MRO_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=2.32987; // from ACE3 checkScopes.sqf
    };
    class JCA_optic_ICO_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.33929; // from ACE3 checkScopes.sqf
    };
    class JCA_optic_AHO_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.80373; // from ACE3 checkScopes.sqf
    };
    class JCA_optic_ARO_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=2.98032; // from ACE3 checkScopes.sqf
    };
    class JCA_optic_AICO_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.15842; // from ACE3 checkScopes.sqf
    };
    class JCA_optic_ACOG_base: ItemCore
    {
        ACE_ScopeHeightAboveRail=4.4543; // from ACE3 checkScopes.sqf
    };
    class JCA_optic_MRPS_base: ItemCore
    {
        ACE_ScopeZeroRange=100; // Always keep vanilla discreteDistance 100 same that Range Card zeroed distance, to increase eventually zeroing distance: Interaction Menu -> "Set zero adjustment" (AB enabled only)
        ACE_ScopeHeightAboveRail=4.51714; // from ACE3 checkScopes.sqf
        descriptionShort="Medium Range Precision Sight<br />Magnification: 4x-10x";
        class ItemInfo: InventoryOpticsItem_Base_F
        {
            mass=13.1; // 21 oz (595g), JCA 14
            class OpticsModes
            {
                class MRPS
                {
                    opticsZoomMin=0.025649; // accurate mRad reticle calibration at magnification 9.7x, JCA 0.0227 (11x)
                    opticsZoomMax=0.060328; // accurate mRad reticle calibration at magnification 4.1x, JCA 0.0536 (4.7x)
                    opticsZoomInit=0.060328; // accurate mRad reticle calibration at magnification 4.1x, JCA 0.0536 (4.7x)
                    discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
                    discreteDistanceInitIndex=0;
                    distanceZoomMin=100;
                    distanceZoomMax=2000;
                    discretefov[]={0.060328,0.025649}; // {4.1x,9.7x}
                };
            };
        };
    };
    class JCA_muzzle_snds_advanced_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class JCA_muzzle_snds_556_advanced_black: JCA_muzzle_snds_advanced_base // Sound Suppressor 5.56mm, muzzle_snds_M
    {
        class ItemInfo: ItemInfo
        {
            mass=8; // muzzle_snds_M, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_M, JCA 0.2, muzzle_snds_M 0.2
    };
    class JCA_muzzle_snds_556_advanced_sand: JCA_muzzle_snds_advanced_base // Sound Suppressor 5.56mm, muzzle_snds_M
    {
        class ItemInfo: ItemInfo
        {
            mass=8; // muzzle_snds_M, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_M, JCA 0.2, muzzle_snds_M 0.2
    };
    class JCA_muzzle_snds_556_advanced_olive: JCA_muzzle_snds_advanced_base // Sound Suppressor 5.56mm, muzzle_snds_M
    {
        class ItemInfo: ItemInfo
        {
            mass=8; // muzzle_snds_M, JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        inertia=0.1; // muzzle_snds_M, JCA 0.2, muzzle_snds_M 0.2
    };
    class JCA_muzzle_snds_tactical_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class JCA_muzzle_snds_762_tactical_black: JCA_muzzle_snds_tactical_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            mass=12.3; // Knights Armament KAC Rifle Suppressors 19.75oz (560g), JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_762_tactical_sand: JCA_muzzle_snds_tactical_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            mass=12.3; // Knights Armament KAC Rifle Suppressors 19.75oz (560g), JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_762_tactical_olive: JCA_muzzle_snds_tactical_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            mass=12.3; // Knights Armament KAC Rifle Suppressors 19.75oz (560g), JCA 12
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_SR25_base: ItemCore
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class JCA_muzzle_snds_SR25_black: JCA_muzzle_snds_SR25_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            mass=18.7; // Knights Armament KAC Mk11 7.62 Suppressor, weight 29.9 oz (848g), JCA 10
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3; // muzzle_snds_B, JCA 0.5, muzzle_snds_570 0.5
                audibleFire=0.04; // muzzle_snds_B, JCA 0.3, muzzle_snds_570 0.3
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_SR25_sand: JCA_muzzle_snds_SR25_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            mass=18.7; // Knights Armament KAC Mk11 7.62 Suppressor, weight 29.9 oz (848g), JCA 10
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3; // muzzle_snds_B, JCA 0.5, muzzle_snds_570 0.5
                audibleFire=0.04; // muzzle_snds_B, JCA 0.3, muzzle_snds_570 0.3
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class JCA_muzzle_snds_SR25_olive: JCA_muzzle_snds_SR25_base // Sound Suppressor 7.62mm, muzzle_snds_B
    {
        class ItemInfo: ItemInfo
        {
            mass=18.7; // Knights Armament KAC Mk11 7.62 Suppressor, weight 29.9 oz (848g), JCA 10
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3; // muzzle_snds_B, JCA 0.5, muzzle_snds_570 0.5
                audibleFire=0.04; // muzzle_snds_B, JCA 0.3, muzzle_snds_570 0.3
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_B 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_B 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
    };
    class muzzle_snds_H: ItemCore // Sound Suppressor 6.5mm
    {
        class ItemInfo: InventoryMuzzleItem_Base_F
        {
        };
    };
    class muzzle_snds_M: muzzle_snds_H // Sound Suppressor 5.56mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=8;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_M 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_M 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.1;
    };
    class muzzle_snds_B: muzzle_snds_H // Sound Suppressor 7.62mm
    {
        class ItemInfo: ItemInfo
        {
            // mass=12;
            class MagazineCoef
            {
                initSpeed=1; // ACE3, JCA 1.05, muzzle_snds_B 1.05
            };
            class AmmoCoef
            {
                hit=1;
                typicalSpeed=1;
                airFriction=1;
                visibleFire=0.3;
                audibleFire=0.04;
                visibleFireTime=0.5;
                audibleFireTime=0.5;
                cost=1;
            };
            class MuzzleCoef
            {
                dispersionCoef=1; // ACE3 0.95, JCA 0.8, muzzle_snds_B 0.8
                artilleryDispersionCoef=1;
                fireLightCoef=0.1;
                recoilCoef=0.95; // ACE3, muzzle_snds_M 1
                recoilProneCoef=0.95; // ACE3, muzzle_snds_M 1
                minRangeCoef=1;
                minRangeProbabCoef=1;
                midRangeCoef=1;
                midRangeProbabCoef=1;
                maxRangeCoef=1;
                maxRangeProbabCoef=1;
            };
        };
        // inertia=0.2;
    };
    class JCA_bipod_04_base: ItemCore
    {
        class ItemInfo: InventoryUnderItem_Base_F
        {
            mass=8.8; // Harris Engineering S-BRM Bipod, weight 14 oz (397g), JCA 10
        };
    };
};
class ACE_ATragMX_Presets
{
    class ld3k_JCA_arifle_SR25_Sierra_MatchKing
    {
        preset[]=
        {
            "JCA Mk11 Mk316",
            790,
            100,
            0.0874179,
            -0.00084907,
            6.94,
            0,
            2,
            10,
            120,
            0,
            0,
            11.34,
            8.31,
            28.575,
            0.489,
            1,
            "ICAO",

            {
                {-15,787},
                {0,788},
                {10,789},
                {15,790},
                {25,793},
                {30,795},
                {35,797}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_arifle_SR25_Lapua_B416
    {
        preset[]=
        {
            "JCA Mk11 Subso",
            331,
            100,
            0.306279,
            -0.00049496,
            6.94,
            0,
            2,
            10,
            120,
            0,
            0,
            12.96,
            8.17,
            28.575,
            0.518,
            1,
            "ICAO",

            {
                {-15,329},
                {0,330},
                {10,331},
                {15,331},
                {25,333},
                {30,334},
                {35,335}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_arifle_SR10_Sierra_MatchKing
    {
        preset[]=
        {
            "JCA SR10 Mk316",
            770,
            100,
            0.0898099,
            -0.00084907,
            6.91,
            0,
            2,
            10,
            120,
            0,
            0,
            11.34,
            8.31,
            25.4,
            0.489,
            1,
            "ICAO",

            {
                {-15,766},
                {0,768},
                {10,769},
                {15,770},
                {25,773},
                {30,775},
                {35,777}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
    class ld3k_JCA_arifle_SR10_Lapua_B416
    {
        preset[]=
        {
            "JCA SR10 Subso",
            323,
            100,
            0.318686,
            -0.00049496,
            6.91,
            0,
            2,
            10,
            120,
            0,
            0,
            12.96,
            8.17,
            25.4,
            0.518,
            1,
            "ICAO",

            {
                {-15,321},
                {0,322},
                {10,322},
                {15,323},
                {25,324},
                {30,325},
                {35,326}
            },

            {
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0},
                {0,0}
            }
        };
    };
};
