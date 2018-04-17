/** @file StaticPropsCmd.hpp
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.6
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef STATICPROPSCMD_H
#define STATICPROPSCMD_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE "StaticProps"
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_PACKAGE_NAME "StaticProps"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION ""
#endif

enum enum_privilegedAxis { privilegedAxis__NULL = -1, privilegedAxis_arg_x = 0, privilegedAxis_arg_y, privilegedAxis_arg_z };
enum enum_privilegedAxis2 { privilegedAxis2__NULL = -1, privilegedAxis2_arg_x = 0, privilegedAxis2_arg_y, privilegedAxis2_arg_z };

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char * input_arg;	/**< @brief input dump file.  */
  char * input_orig;	/**< @brief input dump file original value given at command line.  */
  const char *input_help; /**< @brief input dump file help description.  */
  char * output_arg;	/**< @brief output file name.  */
  char * output_orig;	/**< @brief output file name original value given at command line.  */
  const char *output_help; /**< @brief output file name help description.  */
  int step_arg;	/**< @brief process every n frame (default='1').  */
  char * step_orig;	/**< @brief process every n frame original value given at command line.  */
  const char *step_help; /**< @brief process every n frame help description.  */
  int nbins_arg;	/**< @brief number of bins (general purpose) (default='1').  */
  char * nbins_orig;	/**< @brief number of bins (general purpose) original value given at command line.  */
  const char *nbins_help; /**< @brief number of bins (general purpose) help description.  */
  int nbins_x_arg;	/**< @brief number of bins in x axis (default='100').  */
  char * nbins_x_orig;	/**< @brief number of bins in x axis original value given at command line.  */
  const char *nbins_x_help; /**< @brief number of bins in x axis help description.  */
  int nbins_y_arg;	/**< @brief number of bins in y axis (default='100').  */
  char * nbins_y_orig;	/**< @brief number of bins in y axis original value given at command line.  */
  const char *nbins_y_help; /**< @brief number of bins in y axis help description.  */
  int nbins_z_arg;	/**< @brief number of bins in z axis (default='100').  */
  char * nbins_z_orig;	/**< @brief number of bins in z axis original value given at command line.  */
  const char *nbins_z_help; /**< @brief number of bins in z axis help description.  */
  int nrbins_arg;	/**< @brief number of radial bins (usually duplicates functionality of nbins) (default='100').  */
  char * nrbins_orig;	/**< @brief number of radial bins (usually duplicates functionality of nbins) original value given at command line.  */
  const char *nrbins_help; /**< @brief number of radial bins (usually duplicates functionality of nbins) help description.  */
  int nanglebins_arg;	/**< @brief number of bins for cos(angle) (default='50').  */
  char * nanglebins_orig;	/**< @brief number of bins for cos(angle) original value given at command line.  */
  const char *nanglebins_help; /**< @brief number of bins for cos(angle) help description.  */
  double rcut_arg;	/**< @brief cutoff radius (rcut).  */
  char * rcut_orig;	/**< @brief cutoff radius (rcut) original value given at command line.  */
  const char *rcut_help; /**< @brief cutoff radius (rcut) help description.  */
  double OOcut_arg;	/**< @brief Oxygen-Oxygen cutoff radius (angstroms) (default='3.5').  */
  char * OOcut_orig;	/**< @brief Oxygen-Oxygen cutoff radius (angstroms) original value given at command line.  */
  const char *OOcut_help; /**< @brief Oxygen-Oxygen cutoff radius (angstroms) help description.  */
  double thetacut_arg;	/**< @brief HOO cutoff angle (degrees) (default='30').  */
  char * thetacut_orig;	/**< @brief HOO cutoff angle (degrees) original value given at command line.  */
  const char *thetacut_help; /**< @brief HOO cutoff angle (degrees) help description.  */
  double OHcut_arg;	/**< @brief Oxygen-Hydrogen cutoff radius (angstroms) (default='2.45').  */
  char * OHcut_orig;	/**< @brief Oxygen-Hydrogen cutoff radius (angstroms) original value given at command line.  */
  const char *OHcut_help; /**< @brief Oxygen-Hydrogen cutoff radius (angstroms) help description.  */
  double dz_arg;	/**< @brief slab width (dz).  */
  char * dz_orig;	/**< @brief slab width (dz) original value given at command line.  */
  const char *dz_help; /**< @brief slab width (dz) help description.  */
  double length_arg;	/**< @brief maximum length (Defaults to 1/2 smallest length of first frame).  */
  char * length_orig;	/**< @brief maximum length (Defaults to 1/2 smallest length of first frame) original value given at command line.  */
  const char *length_help; /**< @brief maximum length (Defaults to 1/2 smallest length of first frame) help description.  */
  double zlength_arg;	/**< @brief maximum length (Defaults to 1/2 smallest length of first frame).  */
  char * zlength_orig;	/**< @brief maximum length (Defaults to 1/2 smallest length of first frame) original value given at command line.  */
  const char *zlength_help; /**< @brief maximum length (Defaults to 1/2 smallest length of first frame) help description.  */
  double zoffset_arg;	/**< @brief Where to set the zero for the slab_density calculation (default='0').  */
  char * zoffset_orig;	/**< @brief Where to set the zero for the slab_density calculation original value given at command line.  */
  const char *zoffset_help; /**< @brief Where to set the zero for the slab_density calculation help description.  */
  char * sele1_arg;	/**< @brief select the first stuntdouble set.  */
  char * sele1_orig;	/**< @brief select the first stuntdouble set original value given at command line.  */
  const char *sele1_help; /**< @brief select the first stuntdouble set help description.  */
  char * sele2_arg;	/**< @brief select the second stuntdouble set.  */
  char * sele2_orig;	/**< @brief select the second stuntdouble set original value given at command line.  */
  const char *sele2_help; /**< @brief select the second stuntdouble set help description.  */
  char * sele3_arg;	/**< @brief select the third stuntdouble set.  */
  char * sele3_orig;	/**< @brief select the third stuntdouble set original value given at command line.  */
  const char *sele3_help; /**< @brief select the third stuntdouble set help description.  */
  char * refsele_arg;	/**< @brief select reference (use and only use with --gxyz).  */
  char * refsele_orig;	/**< @brief select reference (use and only use with --gxyz) original value given at command line.  */
  const char *refsele_help; /**< @brief select reference (use and only use with --gxyz) help description.  */
  char * comsele_arg;	/**< @brief select stunt doubles for center-of-mass reference point.  */
  char * comsele_orig;	/**< @brief select stunt doubles for center-of-mass reference point original value given at command line.  */
  const char *comsele_help; /**< @brief select stunt doubles for center-of-mass reference point help description.  */
  int seleoffset_arg;	/**< @brief global index offset for a second object (used to define a vector between sites in molecule).  */
  char * seleoffset_orig;	/**< @brief global index offset for a second object (used to define a vector between sites in molecule) original value given at command line.  */
  const char *seleoffset_help; /**< @brief global index offset for a second object (used to define a vector between sites in molecule) help description.  */
  int seleoffset2_arg;	/**< @brief global index offset for a third object (used to define a vector between sites in molecule).  */
  char * seleoffset2_orig;	/**< @brief global index offset for a third object (used to define a vector between sites in molecule) original value given at command line.  */
  const char *seleoffset2_help; /**< @brief global index offset for a third object (used to define a vector between sites in molecule) help description.  */
  char * molname_arg;	/**< @brief molecule name.  */
  char * molname_orig;	/**< @brief molecule name original value given at command line.  */
  const char *molname_help; /**< @brief molecule name help description.  */
  int begin_arg;	/**< @brief begin internal index.  */
  char * begin_orig;	/**< @brief begin internal index original value given at command line.  */
  const char *begin_help; /**< @brief begin internal index help description.  */
  int end_arg;	/**< @brief end internal index.  */
  char * end_orig;	/**< @brief end internal index original value given at command line.  */
  const char *end_help; /**< @brief end internal index help description.  */
  double radius_arg;	/**< @brief nanoparticle radius.  */
  char * radius_orig;	/**< @brief nanoparticle radius original value given at command line.  */
  const char *radius_help; /**< @brief nanoparticle radius help description.  */
  double voxelSize_arg;	/**< @brief voxel size (angstroms).  */
  char * voxelSize_orig;	/**< @brief voxel size (angstroms) original value given at command line.  */
  const char *voxelSize_help; /**< @brief voxel size (angstroms) help description.  */
  double gaussWidth_arg;	/**< @brief Gaussian width (angstroms).  */
  char * gaussWidth_orig;	/**< @brief Gaussian width (angstroms) original value given at command line.  */
  const char *gaussWidth_help; /**< @brief Gaussian width (angstroms) help description.  */
  enum enum_privilegedAxis privilegedAxis_arg;	/**< @brief which axis is special for spatial analysis (default = z axis) (default='z').  */
  char * privilegedAxis_orig;	/**< @brief which axis is special for spatial analysis (default = z axis) original value given at command line.  */
  const char *privilegedAxis_help; /**< @brief which axis is special for spatial analysis (default = z axis) help description.  */
  enum enum_privilegedAxis2 privilegedAxis2_arg;	/**< @brief which axis is special for spatial analysis (default = x axis) (default='x').  */
  char * privilegedAxis2_orig;	/**< @brief which axis is special for spatial analysis (default = x axis) original value given at command line.  */
  const char *privilegedAxis2_help; /**< @brief which axis is special for spatial analysis (default = x axis) help description.  */
  const char *bo_help; /**< @brief bond order parameter (--rcut must be specified) help description.  */
  const char *ior_help; /**< @brief icosahedral bond order parameter as a function of radius (--rcut must be specified) help description.  */
  const char *for_help; /**< @brief FCC bond order parameter as a function of radius (--rcut must be specified) help description.  */
  const char *bad_help; /**< @brief N(theta) bond angle density within (--rcut must be specified) help description.  */
  const char *count_help; /**< @brief count of molecules matching selection criteria (and associated statistics) help description.  */
  const char *gofr_help; /**< @brief g(r) help description.  */
  const char *gofz_help; /**< @brief g(z) help description.  */
  const char *r_theta_help; /**< @brief g(r, cos(theta)) help description.  */
  const char *r_omega_help; /**< @brief g(r, cos(omega)) help description.  */
  const char *r_z_help; /**< @brief g(r, z) help description.  */
  const char *theta_omega_help; /**< @brief g(cos(theta), cos(omega)) help description.  */
  const char *r_theta_omega_help; /**< @brief g(r, cos(theta), cos(omega)) help description.  */
  const char *gxyz_help; /**< @brief g(x, y, z) help description.  */
  const char *twodgofr_help; /**< @brief 2D g(r) (Slab width --dz must be specified) help description.  */
  const char *p2_help; /**< @brief p2 order parameter (--sele1 must be specified, --sele2 is optional) help description.  */
  const char *rp2_help; /**< @brief rp2 order parameter (--sele1 and --sele2 must be specified) help description.  */
  const char *scd_help; /**< @brief scd order parameter (either --sele1, --sele2, --sele3 are specified or --molname, --begin, --end are specified) help description.  */
  const char *density_help; /**< @brief density plot help description.  */
  const char *slab_density_help; /**< @brief slab density, rho(z) help description.  */
  const char *pipe_density_help; /**< @brief pipe density, rho(axis1, axis2) help description.  */
  const char *p_angle_help; /**< @brief p(cos(theta)) (--sele1 must be specified, --sele2 is optional) help description.  */
  const char *hxy_help; /**< @brief hxy help description.  */
  const char *rho_r_help; /**< @brief rho(R) help description.  */
  const char *angle_r_help; /**< @brief angle of R help description.  */
  const char *hullvol_help; /**< @brief hull volume of nanoparticle help description.  */
  const char *rodlength_help; /**< @brief length of nanorod help description.  */
  const char *tet_param_help; /**< @brief tetrahedrality order parameter (Qk) help description.  */
  const char *tet_param_z_help; /**< @brief spatially-resolved tetrahedrality order parameter Qk(z) help description.  */
  const char *tet_param_dens_help; /**< @brief computes density of the tetrahedrality order parameter Qk help description.  */
  const char *tet_param_xyz_help; /**< @brief volume-resolved tetrahedrality order parameter Qk(x,y,z).  (voxelSize, rcut, and gaussWidth must be specified) help description.  */
  const char *rnemdz_help; /**< @brief slab-resolved RNEMD statistics (temperature, density, velocity) help description.  */
  const char *rnemdr_help; /**< @brief shell-resolved RNEMD statistics (temperature, density, angular velocity) help description.  */
  const char *rnemdrt_help; /**< @brief shell and angle-resolved RNEMD statistics (temperature, density, angular velocity) help description.  */
  const char *nitrile_help; /**< @brief electrostatic potential to frequency map based on the Cho nitrile fits help description.  */
  const char *multipole_help; /**< @brief average multipole moments contained within cutoff spheres as a function of radius help description.  */
  const char *cn_help; /**< @brief Coordination Number Distribution help description.  */
  const char *scn_help; /**< @brief Secondary Coordination Number Distribution help description.  */
  const char *gcn_help; /**< @brief Generalized Coordination Number Distribution help description.  */
  const char *hbond_help; /**< @brief Hydrogen Bonding statistics using geometric criteria (rcut and thetacut must be specified) help description.  */
  const char *potDiff_help; /**< @brief potential energy difference when charge on selection is set to zero help description.  */
  const char *tet_hb_help; /**< @brief hydrogen bond statistics binned by tetrahedrality of donor and acceptor molecules help description.  */
  const char *kirkwood_help; /**< @brief distance-dependent Kirkwood factor help description.  */
  const char *kirkwoodQ_help; /**< @brief distance-dependent Kirkwood factor for quadrupoles help description.  */
  const char *densityfield_help; /**< @brief computes an average density field help description.  */
  const char *velocityfield_help; /**< @brief computes an average velocity field help description.  */
  const char *velocityZ_help; /**< @brief computes an average two-dimensional velocity map help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int input_given ;	/**< @brief Whether input was given.  */
  unsigned int output_given ;	/**< @brief Whether output was given.  */
  unsigned int step_given ;	/**< @brief Whether step was given.  */
  unsigned int nbins_given ;	/**< @brief Whether nbins was given.  */
  unsigned int nbins_x_given ;	/**< @brief Whether nbins_x was given.  */
  unsigned int nbins_y_given ;	/**< @brief Whether nbins_y was given.  */
  unsigned int nbins_z_given ;	/**< @brief Whether nbins_z was given.  */
  unsigned int nrbins_given ;	/**< @brief Whether nrbins was given.  */
  unsigned int nanglebins_given ;	/**< @brief Whether nanglebins was given.  */
  unsigned int rcut_given ;	/**< @brief Whether rcut was given.  */
  unsigned int OOcut_given ;	/**< @brief Whether OOcut was given.  */
  unsigned int thetacut_given ;	/**< @brief Whether thetacut was given.  */
  unsigned int OHcut_given ;	/**< @brief Whether OHcut was given.  */
  unsigned int dz_given ;	/**< @brief Whether dz was given.  */
  unsigned int length_given ;	/**< @brief Whether length was given.  */
  unsigned int zlength_given ;	/**< @brief Whether zlength was given.  */
  unsigned int zoffset_given ;	/**< @brief Whether zoffset was given.  */
  unsigned int sele1_given ;	/**< @brief Whether sele1 was given.  */
  unsigned int sele2_given ;	/**< @brief Whether sele2 was given.  */
  unsigned int sele3_given ;	/**< @brief Whether sele3 was given.  */
  unsigned int refsele_given ;	/**< @brief Whether refsele was given.  */
  unsigned int comsele_given ;	/**< @brief Whether comsele was given.  */
  unsigned int seleoffset_given ;	/**< @brief Whether seleoffset was given.  */
  unsigned int seleoffset2_given ;	/**< @brief Whether seleoffset2 was given.  */
  unsigned int molname_given ;	/**< @brief Whether molname was given.  */
  unsigned int begin_given ;	/**< @brief Whether begin was given.  */
  unsigned int end_given ;	/**< @brief Whether end was given.  */
  unsigned int radius_given ;	/**< @brief Whether radius was given.  */
  unsigned int voxelSize_given ;	/**< @brief Whether voxelSize was given.  */
  unsigned int gaussWidth_given ;	/**< @brief Whether gaussWidth was given.  */
  unsigned int privilegedAxis_given ;	/**< @brief Whether privilegedAxis was given.  */
  unsigned int privilegedAxis2_given ;	/**< @brief Whether privilegedAxis2 was given.  */
  unsigned int bo_given ;	/**< @brief Whether bo was given.  */
  unsigned int ior_given ;	/**< @brief Whether ior was given.  */
  unsigned int for_given ;	/**< @brief Whether for was given.  */
  unsigned int bad_given ;	/**< @brief Whether bad was given.  */
  unsigned int count_given ;	/**< @brief Whether count was given.  */
  unsigned int gofr_given ;	/**< @brief Whether gofr was given.  */
  unsigned int gofz_given ;	/**< @brief Whether gofz was given.  */
  unsigned int r_theta_given ;	/**< @brief Whether r_theta was given.  */
  unsigned int r_omega_given ;	/**< @brief Whether r_omega was given.  */
  unsigned int r_z_given ;	/**< @brief Whether r_z was given.  */
  unsigned int theta_omega_given ;	/**< @brief Whether theta_omega was given.  */
  unsigned int r_theta_omega_given ;	/**< @brief Whether r_theta_omega was given.  */
  unsigned int gxyz_given ;	/**< @brief Whether gxyz was given.  */
  unsigned int twodgofr_given ;	/**< @brief Whether twodgofr was given.  */
  unsigned int p2_given ;	/**< @brief Whether p2 was given.  */
  unsigned int rp2_given ;	/**< @brief Whether rp2 was given.  */
  unsigned int scd_given ;	/**< @brief Whether scd was given.  */
  unsigned int density_given ;	/**< @brief Whether density was given.  */
  unsigned int slab_density_given ;	/**< @brief Whether slab_density was given.  */
  unsigned int pipe_density_given ;	/**< @brief Whether pipe_density was given.  */
  unsigned int p_angle_given ;	/**< @brief Whether p_angle was given.  */
  unsigned int hxy_given ;	/**< @brief Whether hxy was given.  */
  unsigned int rho_r_given ;	/**< @brief Whether rho_r was given.  */
  unsigned int angle_r_given ;	/**< @brief Whether angle_r was given.  */
  unsigned int hullvol_given ;	/**< @brief Whether hullvol was given.  */
  unsigned int rodlength_given ;	/**< @brief Whether rodlength was given.  */
  unsigned int tet_param_given ;	/**< @brief Whether tet_param was given.  */
  unsigned int tet_param_z_given ;	/**< @brief Whether tet_param_z was given.  */
  unsigned int tet_param_dens_given ;	/**< @brief Whether tet_param_dens was given.  */
  unsigned int tet_param_xyz_given ;	/**< @brief Whether tet_param_xyz was given.  */
  unsigned int rnemdz_given ;	/**< @brief Whether rnemdz was given.  */
  unsigned int rnemdr_given ;	/**< @brief Whether rnemdr was given.  */
  unsigned int rnemdrt_given ;	/**< @brief Whether rnemdrt was given.  */
  unsigned int nitrile_given ;	/**< @brief Whether nitrile was given.  */
  unsigned int multipole_given ;	/**< @brief Whether multipole was given.  */
  unsigned int cn_given ;	/**< @brief Whether cn was given.  */
  unsigned int scn_given ;	/**< @brief Whether scn was given.  */
  unsigned int gcn_given ;	/**< @brief Whether gcn was given.  */
  unsigned int hbond_given ;	/**< @brief Whether hbond was given.  */
  unsigned int potDiff_given ;	/**< @brief Whether potDiff was given.  */
  unsigned int tet_hb_given ;	/**< @brief Whether tet_hb was given.  */
  unsigned int kirkwood_given ;	/**< @brief Whether kirkwood was given.  */
  unsigned int kirkwoodQ_given ;	/**< @brief Whether kirkwoodQ was given.  */
  unsigned int densityfield_given ;	/**< @brief Whether densityfield was given.  */
  unsigned int velocityfield_given ;	/**< @brief Whether velocityfield was given.  */
  unsigned int velocityZ_given ;	/**< @brief Whether velocityZ was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
  int staticProps_group_counter; /**< @brief Counter for group staticProps */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief the description string of the program */
extern const char *gengetopt_args_info_description;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * The config file parser (deprecated version)
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_config_file() instead
 */
int cmdline_parser_configfile (const char *filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_config_file (const char *filename,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);

extern const char *cmdline_parser_privilegedAxis_values[];  /**< @brief Possible values for privilegedAxis. */
extern const char *cmdline_parser_privilegedAxis2_values[];  /**< @brief Possible values for privilegedAxis2. */


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* STATICPROPSCMD_H */
