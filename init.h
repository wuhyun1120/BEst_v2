#ifndef INIT_H
#define INIT_H
#include <math.h>

/* Computational parameters */

#define L_MIN 2
#define L_MAX 2500
#define POLARISATION_ON 0

/** 
 * Level of sampling for the r integration
 */
#define R_GRID_DENSITY 3

#define N_SIMS 160    // Number of Gaussian simulations used


/* Map options */

/* Modal parameters */

#define MODE_TYPE 5
/* Type 1: Legendre polynomial modes
 * Type 2: Sinusoidal modes
 * Type 3: A constant mode
 * Type 4: Local type modes
 * Type 5: Equilateral, orthogonal and local type modes
 * Type 6: Philip's 'mixed' modes (1/k and Legendre polynomials)
 * Please edit relevant parameters for the chosen type below */

#if MODE_TYPE == 1
    /* Parameters for the Legendre polynomial modes */

    #define P_MAX 2       // Number of modes
    #define MODE_K_MIN 1e-6 // Minimum k for mode functions
    #define MODE_K_MAX 1e0 // Maximum k for mode functions

#elif MODE_TYPE == 2
    /* Parameters for the sinusoidal modes */

    #define P_MAX 2
    #define MODE_OMEGA 100  // Oscillation frequency in Mpc

#elif MODE_TYPE == 3
    /* A mode for constant shape function.
     * Mainly for testing purposes */
    #define P_MAX 1

#elif MODE_TYPE == 4
    /* Modes for local shape function.
     * Mainly for testing purposes */
    #define P_MAX 4

#elif MODE_TYPE == 5
    #define P_MAX 4     // This is always set to 4
    /* Modes for equilateral, orthogonal and local shape functions */ 

#elif MODE_TYPE == 6
    /* Philip's 'mixed' modes including 1/k and Legendre polynomials */ 

    #define P_MAX 10       // Number of modes
    #define MODE_K_RATIO 350    // Value of kmax / kmin for mode functions

#endif /* MODE_TYPE */


/* Experiment specifications */
#define N_SIDE 2048
#define NPTS_MAP 50331648
#define F_SKY_T 0.76
#define F_SKY_E 0.74

/* Output options */
#define OUTPUT_DIRECTORY "./outputs"
#define OUTPUT_FILENAME "results"

/* Cosmological parameters */
#define DELTA_PHI 1.5714e-8;
#define N_SCALAR 0.96089;
#define K_PIVOT 0.05;

/* Optimisation parameters */
#define N_PATCHES 32
#define PATCH_SIZE (NPTS_MAP / N_PATCHES)

/* Data files in use */

#define MAP_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/map/COM_CMB_IQU-smica_2048_R3.00_full.fits"
#define SIM_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/dx12_v3_smica_cmb_mc_"
#define SIM_NOISE_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/dx12_v3_smica_noise_mc_"

#ifdef USE_NEW_INPAINTED_MAPS
#define BINARY_MAP_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/map/2000_bin_COM_CMB_IQU-smica_2048_R3.00_full"
#define BINARY_SIM_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/2000_bin_dx12_v3_smica_cmb_mc_"
#else
// #define BINARY_MAP_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/map/Planck_2018_smica_CMB_I_Stokes_ring"
#define BINARY_MAP_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/map/bin_COM_CMB_IQU-smica_2048_R3.00_full"
#define BINARY_SIM_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/bin_dx12_v3_smica_cmb_mc_"
#endif
#define BINARY_SIM_ALM_T_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/alms/DX12_inpaint_2000_smica_alm_T_"

#if defined USE_GAUSSIAN_FULL_SKY || defined USE_GAUSSIAN_MASKED
#define RANDOM_SEED_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/random_seeds2"
#endif

#define BINARY_SIM_NOISE_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/bin_dx12_v3_smica_noise_mc_"
#define BINARY_FULL_SKY_SIM_HEADER "/nfs/st01/hpc-gr-epss/ws313/data/simulations/bin_full_sky_gaussian_cmb_"
#define MASK_T_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/common_mask_T"
#define BESSEL_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/bessel_4000"
#define BESSEL_SIZE_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/bessel_4000_size"
//#define BESSEL_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/bessel_5000"
//#define BESSEL_SIZE_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/bessel_5000_size"
#define TRANSFER_T_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/transfer_planck_DDX9_5000_T"
#define TRANSFER_E_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/transfer_planck_DDX9_5000_E"
#define TRANSFER_SIZE_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/transfer_planck_DDX9_5000_size"
/*
#define TRANSFER_T_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/cosmos/transfer_planck_DDX9_3000_T"
#define TRANSFER_E_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/cosmos/transfer_planck_DDX9_3000_E"
#define TRANSFER_SIZE_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/cosmos/transfer_planck_DDX9_3000_size"
*/

#ifdef USE_SIM_CLS
#define C_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/simulation_cls_T"
#else
#define C_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/planck_unlensed_2015_lensedCls.dat"
#endif /* USE_SIM_CLS */

#define BN_TT_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/BN_DX11d_smica_case1_HP_T.txt"
#define BN_EE_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/BN_DX11d_smica_case1_HP_E.txt"
#define PW_T_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/pixel_window_T"
#define PW_E_DATA_FILENAME "/nfs/st01/hpc-gr-epss/ws313/data/pixel_window_E"


/*** Do not edit beyond this point ***/

/* Micellaneous */
#define MAXLEN 200	// Maximum length of string
#define MAXLINES 10000	// Maximum number of lines in a text file
#define pi M_PI


typedef enum polarisation { POL_T, POL_E, POL_TT, POL_TE, POL_EE };

/* Declare global variables */
extern double *r_grid;
extern double *r_weights;
extern int npts_r;


#if MODE_TYPE == 1
extern double mode_k_min;
extern double mode_k_max;

#elif MODE_TYPE == 2
extern double mode_omega;

#elif MODE_TYPE == 6
extern double mode_k_ratio;
extern double mode_k_min;
extern double mode_k_max;

#endif /* MODE_TYPE */

extern char output_directory[MAXLEN];
extern char output_filename[MAXLEN];
extern char job_id_tag[MAXLEN];

extern char map_filename[MAXLEN];
extern char sim_header[MAXLEN];
extern char sim_noise_header[MAXLEN];
extern char binary_map_filename[MAXLEN];
extern char binary_sim_header[MAXLEN];
extern char binary_sim_noise_header[MAXLEN];
extern char binary_sim_alm_T_header[MAXLEN];
extern char binary_full_sky_sim_header[MAXLEN];
extern char mask_T_filename[MAXLEN];
extern char bessel_data_filename[MAXLEN];
extern char bessel_size_filename[MAXLEN];
extern char transfer_T_data_filename[MAXLEN];
extern char transfer_E_data_filename[MAXLEN];
extern char transfer_size_filename[MAXLEN];
extern char C_data_filename[MAXLEN];
extern char BN_TT_data_filename[MAXLEN];
extern char BN_EE_data_filename[MAXLEN];
extern char PW_T_data_filename[MAXLEN];
extern char PW_E_data_filename[MAXLEN];

#if defined USE_GAUSSIAN_FULL_SKY || defined USE_GAUSSIAN_MASKED
extern char random_seed_filename[MAXLEN];
#endif

extern int initialised;

/* Initialising function, defined in init.c */
void initialise(char *job_id);


#endif /* INIT_H */
