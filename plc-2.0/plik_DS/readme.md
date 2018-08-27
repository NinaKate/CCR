This extended Planck likelihood release contains 2 extra CMB likelihood files
* plik_dx11dr2_DS_v18_TT.clik
* plik_dx11dr2_DS_v18_TE.clik
* plik_dx11dr2_DS_v18_EE.clik
* plik_dx11dr2_DS_v18_TTTEEE.clik

They correspond to the plik likelihood for the TT, TE, EE and joint TT, TE and EE 
spectra produced using the weighted average of the detsets binned cross spectra.
The TT part include a correction for the correlated noise.

Similarily to the *HM* plik lkelihoods, the l range for TT is l=30 to 2508 and for
TE and EE, l=30 to 1996.

The nuisance parameters are identical to the baseline plik files.


# plik_dx11dr2_DS_v18_TT.clik

This file can be used to compute the TT only likelihood using the detset cross spectra.
When used with the library, the file expects a vector of parameters consisting in the 
TT power spectrum (l=30 to l=2508) followed by a vector of 20 nuisance parameters. 
Those are, in that order

- A_cib_217, The CIB contamination at l=3000 in the 217GHz Planck map.
- cib_index, The effective slope of the CIB spectrum. This parameter should be set to -1.3
- xi_sz_cib, The szXcib cross correlation
- A_sz, the tSZ contamination at 143GHz
- ps_A_100_100, the point source contribution in 100x100
- ps_A_143_143, the point source contribution in 143x143
- ps_A_143_217, the point source contribution in 143x217
- ps_A_217_217, the point source contribution in 217x217
- ksz_norm, the ksz contamination
- gal545_A_100, the dust residual contamination at l=200 in 100x100
- gal545_A_143, the dust residual contamination at l=200 in 143x143
- gal545_A_143_217, the dust residual contamination at l=200 in 143x217
- gal545_A_217, the dust residual contamination at l=200 in 217x217
- A_cnoise_100_100_TT, multiplicative amplitude for the correlated noise correction in the effective 100x100 TT spectrum, should be set to 1
- A_cnoise_143_143_TT, multiplicative amplitude for the correlated noise correction in the effective 143x100 TT spectrum, should be set to 1
- A_cnoise_143_217_TT, multiplicative amplitude for the correlated noise correction in the effective 143x217 TT spectrum, should be set to 1
- A_cnoise_217_217_TT, multiplicative amplitude for the correlated noise correction in the effective 217x217 TT spectrum, should be set to 1
- calib_100T, the relative calibration between the 100 and 143 spectra
- calib_217T, the relative calibration between the 217 and 143 spectra
- A_planck, the planck absolute calibration

The following priors whould be used

- ksz_norm + 1.6 * A_sz = 9.5 ± 3) 
- cib_index             = -1.3 
- gal545_A_100          = 7±2
- gal545_A_143          = 9±2
- gal545_A_143_217      = 21±8.5
- gal545_A_217          = 80±20
- A_cnoise_100_100_TT   = 1
- A_cnoise_143_143_TT   = 1
- A_cnoise_143_217_TT   = 1
- A_cnoise_217_217_TT   = 1
- calib_100T            = 0.999±0.001
- calib_217T            = 0.995±0.002
- A_planck              = 1±0.0025


# plik_dx11dr2_DS_v18_TE.clik

This file can be used to compute the TE only likelihood using the detset cross spectra.
When used with the library, the file expects a vector of parameters consisting in the 
TT power spectrum (l=30 to l=1996) followed by the EE and TE spectra (same range) and 
by a vector of 44 nuisance parameters. Those are, in that order

- galf_TE_A_100, The dust residual contamination at l=500 in 100x100TE
- galf_TE_A_100_143, The dust residual contamination at l=500 in 100x143TE
- galf_TE_A_100_217, The dust residual contamination at l=500 in 100x217TE
- galf_TE_A_143, The dust residual contamination at l=500 in 143x143TE
- galf_TE_A_143_217, The dust residual contamination at l=500 in 143x217TE
- galf_TE_A_217, The dust residual contamination at l=500 in 217x217TE
- galf_TE_index, the dust EE template slope, should be set to -2.4
- bleak_epsilon_0_0T_0E, Beam leakage parameters, espilon_0, 100x100 TE
- bleak_epsilon_1_0T_0E, Beam leakage parameters, espilon_1, 100x100 TE
- bleak_epsilon_2_0T_0E, Beam leakage parameters, espilon_2, 100x100 TE
- bleak_epsilon_3_0T_0E, Beam leakage parameters, espilon_3, 100x100 TE
- bleak_epsilon_4_0T_0E, Beam leakage parameters, espilon_4, 100x100 TE
- bleak_epsilon_0_0T_1E, Beam leakage parameters, espilon_0, 100x143 TE
- bleak_epsilon_1_0T_1E, Beam leakage parameters, espilon_1, 100x143 TE
- bleak_epsilon_2_0T_1E, Beam leakage parameters, espilon_2, 100x143 TE
- bleak_epsilon_3_0T_1E, Beam leakage parameters, espilon_3, 100x143 TE
- bleak_epsilon_4_0T_1E, Beam leakage parameters, espilon_4, 100x143 TE
- bleak_epsilon_0_0T_2E, Beam leakage parameters, espilon_0, 100x217 TE
- bleak_epsilon_1_0T_2E, Beam leakage parameters, espilon_1, 100x217 TE
- bleak_epsilon_2_0T_2E, Beam leakage parameters, espilon_2, 100x217 TE
- bleak_epsilon_3_0T_2E, Beam leakage parameters, espilon_3, 100x217 TE
- bleak_epsilon_4_0T_2E, Beam leakage parameters, espilon_4, 100x217 TE
- bleak_epsilon_0_1T_1E, Beam leakage parameters, espilon_0, 143x143 TE
- bleak_epsilon_1_1T_1E, Beam leakage parameters, espilon_1, 143x143 TE
- bleak_epsilon_2_1T_1E, Beam leakage parameters, espilon_2, 143x143 TE
- bleak_epsilon_3_1T_1E, Beam leakage parameters, espilon_3, 143x143 TE
- bleak_epsilon_4_1T_1E, Beam leakage parameters, espilon_4, 143x143 TE
- bleak_epsilon_0_1T_2E, Beam leakage parameters, espilon_0, 143x217 TE
- bleak_epsilon_1_1T_2E, Beam leakage parameters, espilon_1, 143x217 TE
- bleak_epsilon_2_1T_2E, Beam leakage parameters, espilon_2, 143x217 TE
- bleak_epsilon_3_1T_2E, Beam leakage parameters, espilon_3, 143x217 TE
- bleak_epsilon_4_1T_2E, Beam leakage parameters, espilon_4, 143x217 TE
- bleak_epsilon_0_2T_2E, Beam leakage parameters, espilon_0, 217x217 TE
- bleak_epsilon_1_2T_2E, Beam leakage parameters, espilon_1, 217x217 TE
- bleak_epsilon_2_2T_2E, Beam leakage parameters, espilon_2, 217x217 TE
- bleak_epsilon_3_2T_2E, Beam leakage parameters, espilon_3, 217x217 TE
- bleak_epsilon_4_2T_2E, Beam leakage parameters, espilon_4, 217x217 TE
- calib_100T, the relative calibration between the 100 and 143 TT spectra
- calib_217T, the relative calibration between the 217 and 143 TT spectra
- calib_100P, the calibration of the 100 EE spectra, This should be set to 1
- calib_143P, the calibration of the 143 EE spectra, This should be set to 1
- calib_217P, the calibration of the 217 EE spectra, This should be set to 1
- A_pol, the calibration of the polarization relative to the temperature, this should be set to 1
- A_planck, the planck absolute calibration

The following priors should be used

- galf_TE_A_100         = 0.14±0.042
- galf_TE_A_100_143     = 0.12±0.036
- galf_TE_A_100_217     = 0.3±0.09
- galf_TE_A_143         = 0.24±0.072
- galf_TE_A_143_217     = 0.6±0.018
- galf_TE_A_217         = 1.8±0.54
- galf_TE_index         = -2.4
- bleak_epsilon_0_0T_0E = 0 
- bleak_epsilon_1_0T_0E = 0
- bleak_epsilon_2_0T_0E = 0
- bleak_epsilon_3_0T_0E = 0
- bleak_epsilon_4_0T_0E = 0
- bleak_epsilon_0_0T_1E = 0
- bleak_epsilon_1_0T_1E = 0
- bleak_epsilon_2_0T_1E = 0
- bleak_epsilon_3_0T_1E = 0
- bleak_epsilon_4_0T_1E = 0
- bleak_epsilon_0_0T_2E = 0
- bleak_epsilon_1_0T_2E = 0
- bleak_epsilon_2_0T_2E = 0
- bleak_epsilon_3_0T_2E = 0
- bleak_epsilon_4_0T_2E = 0
- bleak_epsilon_0_1T_1E = 0
- bleak_epsilon_1_1T_1E = 0
- bleak_epsilon_2_1T_1E = 0
- bleak_epsilon_3_1T_1E = 0
- bleak_epsilon_4_1T_1E = 0
- bleak_epsilon_0_1T_2E = 0
- bleak_epsilon_1_1T_2E = 0
- bleak_epsilon_2_1T_2E = 0
- bleak_epsilon_3_1T_2E = 0
- bleak_epsilon_4_1T_2E = 0
- bleak_epsilon_0_2T_2E = 0
- bleak_epsilon_1_2T_2E = 0
- bleak_epsilon_2_2T_2E = 0
- bleak_epsilon_3_2T_2E = 0
- bleak_epsilon_4_2T_2E = 0
- calib_100T            = 0.999±0.001
- calib_217T            = 0.995±0.002
- calib_100P            = 1      
- calib_143P            = 1      
- calib_217P            = 1      
- A_pol                 = 1 
- A_planck              = 1±0.0025


# plik_dx11dr2_DS_v18_TE.clik

This file can be used to compute the EE only likelihood using the detset cross spectra.
When used with the library, the file expects a vector of parameters consisting in the 
EE power spectrum (l=30 to l=1996) followed by a vector of 42 nuisance parameters. 
Those are, in that order

- galf_EE_A_100, The dust residual contamination at l=500 in 100x100EE
- galf_EE_A_100_143, The dust residual contamination at l=500 in 100x143EE
- galf_EE_A_100_217, The dust residual contamination at l=500 in 100x217EE
- galf_EE_A_143, The dust residual contamination at l=500 in 143x143EE
- galf_EE_A_143_217, The dust residual contamination at l=500 in 143x217EE
- galf_EE_A_217, The dust residual contamination at l=500 in 217x217EE
- galf_EE_index, the dust EE template slope, should be set to -2.4
- bleak_epsilon_0_0E_0E, Beam leakage parameters, espilon_0, 100x100 EE
- bleak_epsilon_1_0E_0E, Beam leakage parameters, espilon_1, 100x100 EE
- bleak_epsilon_2_0E_0E, Beam leakage parameters, espilon_2, 100x100 EE
- bleak_epsilon_3_0E_0E, Beam leakage parameters, espilon_3, 100x100 EE
- bleak_epsilon_4_0E_0E, Beam leakage parameters, espilon_4, 100x100 EE
- bleak_epsilon_0_0E_1E, Beam leakage parameters, espilon_0, 100x143 EE
- bleak_epsilon_1_0E_1E, Beam leakage parameters, espilon_1, 100x143 EE
- bleak_epsilon_2_0E_1E, Beam leakage parameters, espilon_2, 100x143 EE
- bleak_epsilon_3_0E_1E, Beam leakage parameters, espilon_3, 100x143 EE
- bleak_epsilon_4_0E_1E, Beam leakage parameters, espilon_4, 100x143 EE
- bleak_epsilon_0_0E_2E, Beam leakage parameters, espilon_0, 100x217 EE
- bleak_epsilon_1_0E_2E, Beam leakage parameters, espilon_1, 100x217 EE
- bleak_epsilon_2_0E_2E, Beam leakage parameters, espilon_2, 100x217 EE
- bleak_epsilon_3_0E_2E, Beam leakage parameters, espilon_3, 100x217 EE
- bleak_epsilon_4_0E_2E, Beam leakage parameters, espilon_4, 100x217 EE
- bleak_epsilon_0_1E_1E, Beam leakage parameters, espilon_0, 143x143 EE
- bleak_epsilon_1_1E_1E, Beam leakage parameters, espilon_1, 143x143 EE
- bleak_epsilon_2_1E_1E, Beam leakage parameters, espilon_2, 143x143 EE
- bleak_epsilon_3_1E_1E, Beam leakage parameters, espilon_3, 143x143 EE
- bleak_epsilon_4_1E_1E, Beam leakage parameters, espilon_4, 143x143 EE
- bleak_epsilon_0_1E_2E, Beam leakage parameters, espilon_0, 143x217 EE
- bleak_epsilon_1_1E_2E, Beam leakage parameters, espilon_1, 143x217 EE
- bleak_epsilon_2_1E_2E, Beam leakage parameters, espilon_2, 143x217 EE
- bleak_epsilon_3_1E_2E, Beam leakage parameters, espilon_3, 143x217 EE
- bleak_epsilon_4_1E_2E, Beam leakage parameters, espilon_4, 143x217 EE
- bleak_epsilon_0_2E_2E, Beam leakage parameters, espilon_0, 217x217 EE
- bleak_epsilon_1_2E_2E, Beam leakage parameters, espilon_1, 217x217 EE
- bleak_epsilon_2_2E_2E, Beam leakage parameters, espilon_2, 217x217 EE
- bleak_epsilon_3_2E_2E, Beam leakage parameters, espilon_3, 217x217 EE
- bleak_epsilon_4_2E_2E, Beam leakage parameters, espilon_4, 217x217 EE
- calib_100P, the calibration of the 100 EE spectra, This should be set to 1
- calib_143P, the calibration of the 143 EE spectra, This should be set to 1
- calib_217P, the calibration of the 217 EE spectra, This should be set to 1
- A_pol, the calibration of the polarization relative to the temperature, this should be set to 1
- A_planck, the planck absolute calibration

The following priors whould be used

- galf_EE_A_100         = 0.06±0.012
- galf_EE_A_100_143     = 0.05±0.015
- galf_EE_A_100_217     = 0.11±0.033
- galf_EE_A_143         = 0.1±0.02
- galf_EE_A_143_217     = 0.24±0.048
- galf_EE_A_217         = 0.72±0.14
- galf_EE_index         = -2.4
- bleak_epsilon_0_0E_0E = 0 
- bleak_epsilon_1_0E_0E = 0
- bleak_epsilon_2_0E_0E = 0
- bleak_epsilon_3_0E_0E = 0
- bleak_epsilon_4_0E_0E = 0
- bleak_epsilon_0_0E_1E = 0
- bleak_epsilon_1_0E_1E = 0
- bleak_epsilon_2_0E_1E = 0
- bleak_epsilon_3_0E_1E = 0
- bleak_epsilon_4_0E_1E = 0
- bleak_epsilon_0_0E_2E = 0
- bleak_epsilon_1_0E_2E = 0
- bleak_epsilon_2_0E_2E = 0
- bleak_epsilon_3_0E_2E = 0
- bleak_epsilon_4_0E_2E = 0
- bleak_epsilon_0_1E_1E = 0
- bleak_epsilon_1_1E_1E = 0
- bleak_epsilon_2_1E_1E = 0
- bleak_epsilon_3_1E_1E = 0
- bleak_epsilon_4_1E_1E = 0
- bleak_epsilon_0_1E_2E = 0
- bleak_epsilon_1_1E_2E = 0
- bleak_epsilon_2_1E_2E = 0
- bleak_epsilon_3_1E_2E = 0
- bleak_epsilon_4_1E_2E = 0
- bleak_epsilon_0_2E_2E = 0
- bleak_epsilon_1_2E_2E = 0
- bleak_epsilon_2_2E_2E = 0
- bleak_epsilon_3_2E_2E = 0
- bleak_epsilon_4_2E_2E = 0
- calib_100P            = 1      
- calib_143P            = 1      
- calib_217P            = 1      
- A_pol                 = 1 
- A_planck              = 1±0.0025


# plik_dx11dr2_DS_v18_TTTEEE.clik

This file can be used to compute the joint TT, TE and EE likelihood using the detset cross spectra.
When used with the library, the file expects a vector of parameters consisting in the 
TT power spectrum (l=30 to l=2508) followed by the EE and TE spectra (same range) and 
by a vector of 98 nuisance parameters. 
Those are, in that order

- A_cib_217, The CIB contamination at l=3000 in the 217GHz Planck map.
- cib_index, The effective slope of the CIB spectrum. This parameter should be set to -1.3
- xi_sz_cib, The szXcib cross correlation
- A_sz, the tSZ contamination at 143GHz
- ps_A_100_100, the point source contribution in 100x100
- ps_A_143_143, the point source contribution in 143x143
- ps_A_143_217, the point source contribution in 143x217
- ps_A_217_217, the point source contribution in 217x217
- ksz_norm, the ksz contamination
- gal545_A_100, the dust residual contamination at l=200 in 100x100TT
- gal545_A_143, the dust residual contamination at l=200 in 143x143TT
- gal545_A_143_217, the dust residual contamination at l=200 in 143x217TT
- gal545_A_217, the dust residual contamination at l=200 in 217x217TT
- galf_EE_A_100, The dust residual contamination at l=500 in 100x100EE
- galf_EE_A_100_143, The dust residual contamination at l=500 in 100x143EE
- galf_EE_A_100_217, The dust residual contamination at l=500 in 100x217EE
- galf_EE_A_143, The dust residual contamination at l=500 in 143x143EE
- galf_EE_A_143_217, The dust residual contamination at l=500 in 143x217EE
- galf_EE_A_217, The dust residual contamination at l=500 in 217x217EE
- galf_EE_index, the dust EE template slope, should be set to -2.4
- galf_TE_A_100, The dust residual contamination at l=500 in 100x100TE
- galf_TE_A_100_143, The dust residual contamination at l=500 in 100x143TE
- galf_TE_A_100_217, The dust residual contamination at l=500 in 100x217TE
- galf_TE_A_143, The dust residual contamination at l=500 in 143x143TE
- galf_TE_A_143_217, The dust residual contamination at l=500 in 143x217TE
- galf_TE_A_217, The dust residual contamination at l=500 in 217x217TE
- galf_TE_index, the dust EE template slope, should be set to -2.4
- A_cnoise_100_100_TT, multiplicative amplitude for the correlated noise correction in the effective 100x100 TT spectrum, should be set to 1
- A_cnoise_143_143_TT, multiplicative amplitude for the correlated noise correction in the effective 143x100 TT spectrum, should be set to 1
- A_cnoise_143_217_TT, multiplicative amplitude for the correlated noise correction in the effective 143x217 TT spectrum, should be set to 1
- A_cnoise_217_217_TT, multiplicative amplitude for the correlated noise correction in the effective 217x217 TT spectrum, should be set to 1
- bleak_epsilon_0_0T_0E, Beam leakage parameters, espilon_0, 100x100 TE
- bleak_epsilon_1_0T_0E, Beam leakage parameters, espilon_1, 100x100 TE
- bleak_epsilon_2_0T_0E, Beam leakage parameters, espilon_2, 100x100 TE
- bleak_epsilon_3_0T_0E, Beam leakage parameters, espilon_3, 100x100 TE
- bleak_epsilon_4_0T_0E, Beam leakage parameters, espilon_4, 100x100 TE
- bleak_epsilon_0_0T_1E, Beam leakage parameters, espilon_0, 100x143 TE
- bleak_epsilon_1_0T_1E, Beam leakage parameters, espilon_1, 100x143 TE
- bleak_epsilon_2_0T_1E, Beam leakage parameters, espilon_2, 100x143 TE
- bleak_epsilon_3_0T_1E, Beam leakage parameters, espilon_3, 100x143 TE
- bleak_epsilon_4_0T_1E, Beam leakage parameters, espilon_4, 100x143 TE
- bleak_epsilon_0_0T_2E, Beam leakage parameters, espilon_0, 100x217 TE
- bleak_epsilon_1_0T_2E, Beam leakage parameters, espilon_1, 100x217 TE
- bleak_epsilon_2_0T_2E, Beam leakage parameters, espilon_2, 100x217 TE
- bleak_epsilon_3_0T_2E, Beam leakage parameters, espilon_3, 100x217 TE
- bleak_epsilon_4_0T_2E, Beam leakage parameters, espilon_4, 100x217 TE
- bleak_epsilon_0_1T_1E, Beam leakage parameters, espilon_0, 143x143 TE
- bleak_epsilon_1_1T_1E, Beam leakage parameters, espilon_1, 143x143 TE
- bleak_epsilon_2_1T_1E, Beam leakage parameters, espilon_2, 143x143 TE
- bleak_epsilon_3_1T_1E, Beam leakage parameters, espilon_3, 143x143 TE
- bleak_epsilon_4_1T_1E, Beam leakage parameters, espilon_4, 143x143 TE
- bleak_epsilon_0_1T_2E, Beam leakage parameters, espilon_0, 143x217 TE
- bleak_epsilon_1_1T_2E, Beam leakage parameters, espilon_1, 143x217 TE
- bleak_epsilon_2_1T_2E, Beam leakage parameters, espilon_2, 143x217 TE
- bleak_epsilon_3_1T_2E, Beam leakage parameters, espilon_3, 143x217 TE
- bleak_epsilon_4_1T_2E, Beam leakage parameters, espilon_4, 143x217 TE
- bleak_epsilon_0_2T_2E, Beam leakage parameters, espilon_0, 217x217 TE
- bleak_epsilon_1_2T_2E, Beam leakage parameters, espilon_1, 217x217 TE
- bleak_epsilon_2_2T_2E, Beam leakage parameters, espilon_2, 217x217 TE
- bleak_epsilon_3_2T_2E, Beam leakage parameters, espilon_3, 217x217 TE
- bleak_epsilon_4_2T_2E, Beam leakage parameters, espilon_4, 217x217 TE
- bleak_epsilon_0_0E_0E, Beam leakage parameters, espilon_0, 100x100 EE
- bleak_epsilon_1_0E_0E, Beam leakage parameters, espilon_1, 100x100 EE
- bleak_epsilon_2_0E_0E, Beam leakage parameters, espilon_2, 100x100 EE
- bleak_epsilon_3_0E_0E, Beam leakage parameters, espilon_3, 100x100 EE
- bleak_epsilon_4_0E_0E, Beam leakage parameters, espilon_4, 100x100 EE
- bleak_epsilon_0_0E_1E, Beam leakage parameters, espilon_0, 100x143 EE
- bleak_epsilon_1_0E_1E, Beam leakage parameters, espilon_1, 100x143 EE
- bleak_epsilon_2_0E_1E, Beam leakage parameters, espilon_2, 100x143 EE
- bleak_epsilon_3_0E_1E, Beam leakage parameters, espilon_3, 100x143 EE
- bleak_epsilon_4_0E_1E, Beam leakage parameters, espilon_4, 100x143 EE
- bleak_epsilon_0_0E_2E, Beam leakage parameters, espilon_0, 100x217 EE
- bleak_epsilon_1_0E_2E, Beam leakage parameters, espilon_1, 100x217 EE
- bleak_epsilon_2_0E_2E, Beam leakage parameters, espilon_2, 100x217 EE
- bleak_epsilon_3_0E_2E, Beam leakage parameters, espilon_3, 100x217 EE
- bleak_epsilon_4_0E_2E, Beam leakage parameters, espilon_4, 100x217 EE
- bleak_epsilon_0_1E_1E, Beam leakage parameters, espilon_0, 143x143 EE
- bleak_epsilon_1_1E_1E, Beam leakage parameters, espilon_1, 143x143 EE
- bleak_epsilon_2_1E_1E, Beam leakage parameters, espilon_2, 143x143 EE
- bleak_epsilon_3_1E_1E, Beam leakage parameters, espilon_3, 143x143 EE
- bleak_epsilon_4_1E_1E, Beam leakage parameters, espilon_4, 143x143 EE
- bleak_epsilon_0_1E_2E, Beam leakage parameters, espilon_0, 143x217 EE
- bleak_epsilon_1_1E_2E, Beam leakage parameters, espilon_1, 143x217 EE
- bleak_epsilon_2_1E_2E, Beam leakage parameters, espilon_2, 143x217 EE
- bleak_epsilon_3_1E_2E, Beam leakage parameters, espilon_3, 143x217 EE
- bleak_epsilon_4_1E_2E, Beam leakage parameters, espilon_4, 143x217 EE
- bleak_epsilon_0_2E_2E, Beam leakage parameters, espilon_0, 217x217 EE
- bleak_epsilon_1_2E_2E, Beam leakage parameters, espilon_1, 217x217 EE
- bleak_epsilon_2_2E_2E, Beam leakage parameters, espilon_2, 217x217 EE
- bleak_epsilon_3_2E_2E, Beam leakage parameters, espilon_3, 217x217 EE
- bleak_epsilon_4_2E_2E, Beam leakage parameters, espilon_4, 217x217 EE
- calib_100T, the relative calibration between the 100 and 143 TT spectra
- calib_217T, the relative calibration between the 217 and 143 TT spectra
- calib_100P, the calibration of the 100 EE spectra, This should be set to 1
- calib_143P, the calibration of the 143 EE spectra, This should be set to 1
- calib_217P, the calibration of the 217 EE spectra, This should be set to 1
- A_pol, the calibration of the polarization relative to the temperature, this should be set to 1
- A_planck, the planck absolute calibration

The following priors whould be used

- ksz_norm + 1.6 * A_sz = 9.5 ± 3) 
- cib_index             = -1.3 
- gal545_A_100          = 7±2
- gal545_A_143          = 9±2
- gal545_A_143_217      = 21±8.5
- gal545_A_217          = 80±20
- galf_EE_A_100         = 0.06±0.012
- galf_EE_A_100_143     = 0.05±0.015
- galf_EE_A_100_217     = 0.11±0.033
- galf_EE_A_143         = 0.1±0.02
- galf_EE_A_143_217     = 0.24±0.048
- galf_EE_A_217         = 0.72±0.14
- galf_EE_index         = -2.4
- galf_TE_A_100         = 0.14±0.042
- galf_TE_A_100_143     = 0.12±0.036
- galf_TE_A_100_217     = 0.3±0.09
- galf_TE_A_143         = 0.24±0.072
- galf_TE_A_143_217     = 0.6±0.018
- galf_TE_A_217         = 1.8±0.54
- galf_TE_index         = -2.4
- A_cnoise_100_100_TT   = 1
- A_cnoise_143_143_TT   = 1
- A_cnoise_143_217_TT   = 1
- A_cnoise_217_217_TT   = 1
- bleak_epsilon_0_0T_0E = 0 
- bleak_epsilon_1_0T_0E = 0
- bleak_epsilon_2_0T_0E = 0
- bleak_epsilon_3_0T_0E = 0
- bleak_epsilon_4_0T_0E = 0
- bleak_epsilon_0_0T_1E = 0
- bleak_epsilon_1_0T_1E = 0
- bleak_epsilon_2_0T_1E = 0
- bleak_epsilon_3_0T_1E = 0
- bleak_epsilon_4_0T_1E = 0
- bleak_epsilon_0_0T_2E = 0
- bleak_epsilon_1_0T_2E = 0
- bleak_epsilon_2_0T_2E = 0
- bleak_epsilon_3_0T_2E = 0
- bleak_epsilon_4_0T_2E = 0
- bleak_epsilon_0_1T_1E = 0
- bleak_epsilon_1_1T_1E = 0
- bleak_epsilon_2_1T_1E = 0
- bleak_epsilon_3_1T_1E = 0
- bleak_epsilon_4_1T_1E = 0
- bleak_epsilon_0_1T_2E = 0
- bleak_epsilon_1_1T_2E = 0
- bleak_epsilon_2_1T_2E = 0
- bleak_epsilon_3_1T_2E = 0
- bleak_epsilon_4_1T_2E = 0
- bleak_epsilon_0_2T_2E = 0
- bleak_epsilon_1_2T_2E = 0
- bleak_epsilon_2_2T_2E = 0
- bleak_epsilon_3_2T_2E = 0
- bleak_epsilon_4_2T_2E = 0
- bleak_epsilon_0_0E_0E = 0 
- bleak_epsilon_1_0E_0E = 0
- bleak_epsilon_2_0E_0E = 0
- bleak_epsilon_3_0E_0E = 0
- bleak_epsilon_4_0E_0E = 0
- bleak_epsilon_0_0E_1E = 0
- bleak_epsilon_1_0E_1E = 0
- bleak_epsilon_2_0E_1E = 0
- bleak_epsilon_3_0E_1E = 0
- bleak_epsilon_4_0E_1E = 0
- bleak_epsilon_0_0E_2E = 0
- bleak_epsilon_1_0E_2E = 0
- bleak_epsilon_2_0E_2E = 0
- bleak_epsilon_3_0E_2E = 0
- bleak_epsilon_4_0E_2E = 0
- bleak_epsilon_0_1E_1E = 0
- bleak_epsilon_1_1E_1E = 0
- bleak_epsilon_2_1E_1E = 0
- bleak_epsilon_3_1E_1E = 0
- bleak_epsilon_4_1E_1E = 0
- bleak_epsilon_0_1E_2E = 0
- bleak_epsilon_1_1E_2E = 0
- bleak_epsilon_2_1E_2E = 0
- bleak_epsilon_3_1E_2E = 0
- bleak_epsilon_4_1E_2E = 0
- bleak_epsilon_0_2E_2E = 0
- bleak_epsilon_1_2E_2E = 0
- bleak_epsilon_2_2E_2E = 0
- bleak_epsilon_3_2E_2E = 0
- bleak_epsilon_4_2E_2E = 0
- calib_100T            = 0.999±0.001
- calib_217T            = 0.995±0.002
- calib_100P            = 1      
- calib_143P            = 1      
- calib_217P            = 1      
- A_pol                 = 1 
- A_planck              = 1±0.0025
