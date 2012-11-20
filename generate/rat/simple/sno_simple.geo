
///////////////////////////////////////////////////////////////////////
// Last svn revision: $Id$
////////////////////////////////////////////////////////////////////////
// Simplified SNO detector geometry, for SNOMAN salt phase comparisons

{
name: "GEO",
index: "world",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 1, // omitted for visualization

mother: "", // world volume has no mother

type: "box",
size: [20000.0, 20000.0, 20000.0], // mm

material: "rock",
color: [0.67, 0.29, 0.0],
}

{
name: "GEO",
index: "cavity",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 1, // omitted for visualization

mother: "world",

type: "box",
size: [13000.0, 13000.0, 13000.0], // mm
position: [0.0, 0.0, 0.0], // standard setting to move position relative to center of mother
rotation: [0.0, 0.0, 0.0], // standard setting to rotate object (no translation required here)

material: "lightwater_snoman_salt",
color: [1.0, 1.0, 1.0],

}

// -------- GEO[psup]
{
name: "GEO",
index: "psup",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 1, // omitted for visualization

mother: "cavity",

type: "snovessel",
r_maxs: 8900.0, // Outer radius, mm
r_maxt: 793.75,  // Tube radius
size_z:	3900.0, // Tube height, mm (replaced below with water)

material: "acrylic_black",
color: [1.0, 1.0, 1.0],

}

{
name: "GEO",
index: "h2o",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 1, // omitted for visualization

mother: "psup",

type: "snovessel",
r_maxs: 8800.0, // Outer radius, mm
r_maxt: 793.75,  // Tube radius
size_z: 3900.0, // Tube height

material: "lightwater_snoman_salt",
color: [0.7, 0.4, 0.5, 0.1],
}

{
name: "GEO",
index: "h2o_sub",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 1, // omitted for visualization

mother: "h2o",

type: "snovessel",
r_maxs: 8300.0, // Outer radius, mm
r_maxt: 793.75,  // Tube radius
size_z: 4500.0, // Tube height

material: "lightwater_snoman_salt",
color: [0.7, 0.4, 0.5, 0.1],
}

{
name: "GEO",
index: "av",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 0, // omitted for visualization

mother: "h2o_sub",

type: "snovessel",

// Warning: changing these values may cause geometry problems

r_maxs: 6060.4, // Sphere Outer radius of the Vessel, mm
r_maxt: 793.75,  // Tower Outer radius of the Vessel, mm
size_z: 6421.0, // Tower Height

material: "acrylic_snoman_salt",
color: [1.0, 1.0, 0.0, 0.2],
}

{
name: "GEO",
index: "avneck",
valid_begin: [0, 0],
valid_end: [0, 0],
invisible: 0, // omitted for visualization
enable: 1,

mother: "av",

type: "tube",

// Warning: changing these values may cause geometry problems

r_max: 785.0, // Sphere Outer radius of the Vessel, mm
r_min: 730.0,  // Tower Outer radius of the Vessel, mm
size_z: 3210.5, // half height
position: [0.0, 0.0, 9049.5],	// where does the dark acrylic start?

material: "acrylic_dark_snoman",
color: [1.0, 0.8, 0.0,0.8],
}

{
name: "GEO",
index: "innerPMT",
valid_begin: [0, 0],
valid_end: [0, 0],

enable: 1,
vis_simple: 1,
invisible: 1,

mother: "h2o",

type: "panelbuilder",

pmt_build_type: [1], // NORMAL
pmt_type: ["s1408"],

add_concentrator: [1],
concentrator_type: ["cSNOMAN"],

add_bucket: [1],
bucket_type: ["bSNOMAN"],

add_pmtbase: [0],
pmtbase_type: ["r1408"],

grey_disc: [0],
grey_disc_model_params: ["DiscOpticsSNOMAN_salt"],

efficiency_correction: [0.786104d], // Hang over from GLG4PMTOpticalModel, only use if you want to use the GLG4 model

sensitive_detector: "/mydet/pmt/inner",
}

{
name: "GEO",
index: "outerPMT",
valid_begin: [0, 0],
valid_end: [0, 0],

enable: 1,
vis_simple: 1,
invisible: 1,

mother: "cavity",

type: "pmtbuilder",

pmt_build_type: [2], // OWL
pmt_type: ["s1408"],

add_concentrator: [0],
concentrator_type: ["cSNOMAN"],

add_bucket: [0],
bucket_type: ["bSNOMAN"],

add_pmtbase: [0],
pmtbase_type: ["r1408"],

grey_disc: [0],
grey_disc_model_params: ["DiscOpticsSNOMAN_salt"],

efficiency_correction: [0.786104d], // Hang over from GLG4PMTOpticalModel, only use if you want to use the GLG4 model

sensitive_detector: "/mydet/pmt/owl",
}

{
name: "GEO",
index: "scint",
valid_begin: [0, 0],
valid_end: [0, 0],

mother: "av",

type: "snovessel", // same type as AV, just different material

// Warning: changing these values may cause geometry problems

r_maxs: 6005.3, // Sphere Outer radius, mm
r_maxt: 728.98, // Tower Inner radius, mm
size_z: 6421.0, //Tube Height

material: "heavywater_snoman_salt",
color: [0.6, 0.3, 1.0, 0.2],
}
