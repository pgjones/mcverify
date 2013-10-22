// Simplified SNO detector geometry, for SNOMAN salt phase comparisons
{
name: "GEO",
index: "world",
valid_begin: [0, 0],
valid_end: [0, 0],

factory: "solid",
solid: "box",

mother: "", // world volume has no mother

half_size: [20000.0, 20000.0, 40000.0], // mm

material: "rock",

vis_invisible: 0,
vis_style: "wireframe",
vis_color: [0.67, 0.29, 0.0],
}

{
name: "GEO",
index: "cavity",
valid_begin: [0, 0],
valid_end: [0, 0],

factory: "solid",
solid: "tube",

mother: "world", 

r_max: 10000.0,
half_z: 15000.0,

material: "lightwater_snoman_salt",

vis_invisible: 1,
vis_style: "wireframe",
vis_color: [0.67, 0.29, 0.0],
}

{
name: "GEO",
index: "outerPMT",
valid_begin: [0, 0],
valid_end: [0, 0],

mother: "cavity",

factory: "pmtbuilder",

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

sensitive_detector: "/mydet/pmt/owl",

vis_simple: 1,
vis_invisible: 0,
}

{
name: "GEO",
index: "innerPMT",
valid_begin: [0, 0],
valid_end: [0, 0],

mother: "cavity",

factory: "panelbuilder",

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

sensitive_detector: "/mydet/pmt/inner",

vis_simple: 1,
vis_invisible: 1,
}

{
name: "GEO",
index: "av",
valid_begin: [0, 0],
valid_end: [0, 0],
enable: 1,

factory: "solid",

mother: "cavity",

solid_definition: "acrylic_vessel_outer",

material: "acrylic_snoman_salt",

vis_invisible: 1,
vis_style: "wireframe",
vis_color: [0.0, 0.0, 0.0],
}

{
name: "GEO",
index: "neck",
valid_begin: [0, 0],
valid_end: [0, 0],

factory: "solid",
solid: "tube",

mother: "av",

r_min: 730.0, 
r_max: 785.0,
half_z: 3210.5,

material: "acrylic_dark_snoman",

position: [0.0, 0.0, 9049.5],

vis_invisible: 1,
vis_style: "wireframe",
vis_color: [0.67, 0.29, 0.0],
}

{
name: "GEO",
index: "scint",
valid_begin: [0, 0],
valid_end: [0, 0],
enable: 1,

factory: "solid",

mother: "av",

solid_definition: "acrylic_vessel_inner",

material: "heavywater_snoman_salt",

vis_invisible: 1,
vis_style: "wireframe",
vis_color: [0.0, 0.0, 0.0],
}