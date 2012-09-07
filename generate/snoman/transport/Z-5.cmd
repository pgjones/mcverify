titles qio_data.dat
titles dmm.dat
titles casl.dat
set bank TDMM 1 word 14 to 0
set bank TQIO 3 word 19 to 0
set bank TQIO 3 word 5 to 1
titles anxx_nu_0000020674_p3.dat
titles DQXX_0000020674.dat
file QIO 1 Z-5.root
 
$mcrun 20675
$mc_event_rate 50.00 $per_sec
$mc_gen_run_cond $on

***   MC Generation
$mc_num_seed_vx 1
$mc_interaction_type   $start_photon_bomb
$mc_position           $pos_point 0.0 0.0 -500.0
$mc_direction          $dir_isotropic
$mc_energy             $en_mono           3.216e-6 *386nm
$mc_time               $tim_fixed         0.0
$mc_miscellaneous      $misc_random_pol
$mc_misc_num_photons   10000
$num_events            1000

define event_loop
   call mco
   call ftt
   call ftp
   call ftu
   call qio(2)
quit_event
end_def

***   Job control
$pegs_file       'pegs4_10.dat     '
$egs4_ds         $on
*$starting_seed   5674 13359 0
*$starting_seed_2 29527 20766 0
$killvx                0
$mcdaq_ztell           $off
$fresnel_scat          $on
$rayleigh_scat         $on
$photodisintegration   $on

*** Enable belly plate and rope geometry, and tiles themselves
@geom_belly_plate_rope
*@geom_acrylic_tiles
$max_cer_ge_errors 20

$geom_media 200 400 *Me

*** 3d PMT modelling
$3d_pmt
$mc_drift_attenuation $off *Me
$mc_drift_pmt_coll $off *Me
$pmt_var $off *Me

*** Run conditions
*$mc_event_rate 10.00 $per_sec
*$mc_gen_run_cond $on

@load_salt_settings
@run_snodb
