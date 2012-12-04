set bank GEDS 150 word 1 to 0 *Me
set bank GEDS 151 word 1 to 0 *Me
set bank GEDS 152 word 1 to 0 *Me
set bank GEDS 153 word 1 to 0 *Me
set bank GEDS 160 word 1 to 0 *Me
set bank GEDS 161 word 1 to 0 *Me
set bank GEDS 162 word 1 to 0 *Me
set bank GEDS 163 word 1 to 0 *Me
set bank GEDS 164 word 1 to 0 *Me
set bank GEDS 165 word 1 to 0 *Me
set bank GEDS 166 word 1 to 0 *Me
set bank GEDS 167 word 1 to 0 *Me
set bank GEDS 168 word 1 to 0 *Me

*set bank GEDS 423 word 2 to 0 *PHIL HACK, black PMT
*set bank GEDS 423 word 19 to 0 *PHIL HACK, all absorbed photons cause signal
*set bank GEDS 425 word 17 to 0 *PHIL HACK, 80% reflective concentrator
set bank MCDQ 1 word 27 to 0 *PHIL HACK, no DQXX

titles casl.dat
titles dmm.dat
titles qio_pmt.dat *Me
set bank TQIO 3 word 19 to 0
file QIO 1 PRGamma.root
$suppress_geo_err_print

$mc_num_seed_vx 1 *Me

***   MC Generation
$mc_interaction_type   $start$$gamma
$mc_position $pos_region 2. $D2O$0000. 1. $ACRC_IVL$0000. 1.
$mc_direction          $dir_isotropic
$mc_energy             $en_mono        6.13
$num_events            200
$mc_time               $tim_fixed 0.0

set bank TDMM 1 word 14 to 0
$pegs_file            'pegs4_10.dat      '
$egs4_ds $on
$num_events            200
$killvx                0
$mcdaq_hthresh         0.
$mcdaq_cthresh         0.
$mcdaq_ztell           $off
$fresnel_scat          $on
$rayleigh_scat         $on
$photodisintegration   $on
$mc_num_seed_vx 1
define event_loop
    call MCO
    call FTQ
    call FTT
    call FTP
    call FTU
    call RSP(9)
    call FTK(9)
    call RSP(10)
    call FTK(10)
    call CLN
    call QIO(2)
    quit_event
 end_def
$mcrun 20674
$mc_event_rate 50.00 $per_sec
$mc_gen_run_cond $on
$mc_gen_source_run $on
set bank TQIO 3 word 5 to 1
$starting_seed 5674 13359 0
$starting_seed_2 29527 20766 0
$mc_drift_attenuation $off *Me
$mc_drift_pmt_coll $off *Me
$pmt_var $off *Me
@load_salt_settings
@run_snodb
