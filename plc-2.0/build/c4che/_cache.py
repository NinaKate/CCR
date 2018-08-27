AR = ['/usr/bin/ar']
ARFLAGS = ['rcs']
BINDIR = '/user/ninastei/CCR/plc-2.0/bin'
CC = ['/usr/bin/gcc']
CCFLAGS = ['-m64']
CCFLAGS_cc_omp = ['-fopenmp']
CCLNK_SRC_F = []
CCLNK_TGT_F = ['-o']
CC_NAME = 'gcc'
CC_SRC_F = []
CC_TGT_F = ['-c', '-o']
CC_VERSION = ('4', '8', '5')
CFLAGS_MACBUNDLE = ['-fPIC']
CFLAGS_PYEMBED = ['-fno-strict-aliasing', '-fexceptions', '-fstack-protector-strong', '-m64', '-mtune=generic', '-fPIC', '-fwrapv', '-fexceptions', '-fstack-protector-strong', '-m64', '-mtune=generic', '-fPIC', '-fwrapv']
CFLAGS_cpic = ['-fPIC']
CFLAGS_cshlib = ['-fPIC', '-shared']
CPPPATH_ST = '-I%s'
CXXFLAGS_PYEMBED = ['-fno-strict-aliasing', '-fexceptions', '-fstack-protector-strong', '-m64', '-mtune=generic', '-fPIC', '-fwrapv', '-fexceptions', '-fstack-protector-strong', '-m64', '-mtune=generic', '-fPIC', '-fwrapv']
CYTHON = ['/user/ninastei/CCR/plc-2.0/bin/cython']
DEFINES = ['PYTHONDIR="/usr/lib/python2.7/site-packages"', 'PYTHONARCHDIR="/usr/lib64/python2.7/site-packages"', 'HAVE_PYEMBED=1', 'HAVE_PYTHON_H=1']
DEFINES_PYEMBED = ['HAVE_PYEMBED=1', '_GNU_SOURCE', 'NDEBUG', '_GNU_SOURCE']
DEFINES_ST = '-D%s'
DEFINES_cfitsio = []
DEFINES_lapack = ['HAS_LAPACK', 'LAPACK_CLIK']
DEFINES_pmc = []
DEST_BINFMT = 'elf'
DEST_CPU = 'x86_64'
DEST_OS = 'linux'
FC = ['/usr/bin/gfortran']
FCDEFINES_ST = '-D%s'
FCFLAGS = ['-DGFORTRAN', '-ffixed-line-length-0', '-ffree-line-length-0', '-m64']
FCFLAGS_DEBUG = ['-Werror']
FCFLAGS_fc_omp = ['-fopenmp']
FCFLAGS_fcshlib = ['-fPIC', '-shared']
FCFLAGS_fpic = ['-fPIC']
FCINCPATH_ST = '-I%s'
FCLIBPATH_ST = '-L%s'
FCLIB_ST = '-l%s'
FCLNK_SRC_F = []
FCLNK_TGT_F = ['-o']
FCSHLIB_MARKER = ['']
FCSTLIBPATH_ST = '-L%s'
FCSTLIB_MARKER = ['-m64']
FCSTLIB_ST = '-l%s'
FC_NAME = 'GFORTRAN'
FC_SRC_F = []
FC_TGT_F = ['-c', '-o']
FC_VERSION = ('4', '8', '5')
FORTRANMODFLAG = ['-J', '']
FRAMEWORKPATH_DAXPY = []
FRAMEWORKPATH_DDOT = []
FRAMEWORKPATH_DGEMM = []
FRAMEWORKPATH_DGEMV = []
FRAMEWORKPATH_DGEQRF = []
FRAMEWORKPATH_DGESVD = []
FRAMEWORKPATH_DLAMCH = []
FRAMEWORKPATH_DORMQR = []
FRAMEWORKPATH_DPOSV = []
FRAMEWORKPATH_DPOTRF = []
FRAMEWORKPATH_DPOTRI = []
FRAMEWORKPATH_DPOTRS = []
FRAMEWORKPATH_DSYEV = []
FRAMEWORKPATH_DSYEVD = []
FRAMEWORKPATH_DSYEVR = []
FRAMEWORKPATH_DSYMM = []
FRAMEWORKPATH_DSYMV = []
FRAMEWORKPATH_DSYR = []
FRAMEWORKPATH_DSYR2K = []
FRAMEWORKPATH_DSYRK = []
FRAMEWORKPATH_DTRMM = []
FRAMEWORKPATH_DTRMV = []
FRAMEWORKPATH_DTRSM = []
FRAMEWORKPATH_DTRSV = []
FRAMEWORKPATH_DTRTRI = []
FRAMEWORKPATH_FITS_INIT_CFITSIO = []
FRAMEWORKPATH_cfitsio = []
FRAMEWORKPATH_lapack = []
FRAMEWORK_DAXPY = []
FRAMEWORK_DDOT = []
FRAMEWORK_DGEMM = []
FRAMEWORK_DGEMV = []
FRAMEWORK_DGEQRF = []
FRAMEWORK_DGESVD = []
FRAMEWORK_DLAMCH = []
FRAMEWORK_DORMQR = []
FRAMEWORK_DPOSV = []
FRAMEWORK_DPOTRF = []
FRAMEWORK_DPOTRI = []
FRAMEWORK_DPOTRS = []
FRAMEWORK_DSYEV = []
FRAMEWORK_DSYEVD = []
FRAMEWORK_DSYEVR = []
FRAMEWORK_DSYMM = []
FRAMEWORK_DSYMV = []
FRAMEWORK_DSYR = []
FRAMEWORK_DSYR2K = []
FRAMEWORK_DSYRK = []
FRAMEWORK_DTRMM = []
FRAMEWORK_DTRMV = []
FRAMEWORK_DTRSM = []
FRAMEWORK_DTRSV = []
FRAMEWORK_DTRTRI = []
FRAMEWORK_FITS_INIT_CFITSIO = []
FRAMEWORK_ST = ''
FRAMEWORK_cfitsio = []
FRAMEWORK_lapack = []
GCC_VERSION = '4.8.5'
HAVE_PYEMBED = 1
INCDIR = '/user/ninastei/CCR/plc-2.0/include'
INCLUDES_PYEMBED = ['/usr/include/python2.7', '/usr/lib64/python2.7/site-packages/numpy/core/include']
INCLUDES_PYEXT = ['/usr/include/python2.7', '/usr/lib64/python2.7/site-packages/numpy/core/include']
INCLUDES_cfitsio = ['/user/ninastei/CCR/plc-2.0/include']
INCLUDES_lapack = ['/user/ninastei/CCR/plc-2.0/include']
INCLUDES_pmc = []
LIBDIR = '/user/ninastei/CCR/plc-2.0/lib'
LIBPATH_PYEMBED = ['/usr/lib64']
LIBPATH_PYEXT = ['/usr/lib64']
LIBPATH_ST = '-L%s'
LIBPATH_cfitsio = ['/user/ninastei/CCR/plc-2.0/lib']
LIBPATH_fc_runtime = ['/user/ninastei/CCR/plc-2.0']
LIBPATH_lapack = []
LIB_PYEMBED = ['m', 'dl', 'util', 'pthread', 'python2.7']
LIB_PYEXT = ['m', 'dl', 'util', 'pthread']
LIB_ST = '-l%s'
LIB_cfitsio = ['cfitsio']
LIB_dl = ['dl']
LIB_fc_runtime = ['gfortran', 'gomp']
LIB_lapack = ['lapack', 'blas']
LINKFLAGS = ['-m64']
LINKFLAGS_MACBUNDLE = ['-bundle', '-undefined', 'dynamic_lookup']
LINKFLAGS_PYEMBED = ['-Xlinker', '-export-dynamic']
LINKFLAGS_cshlib = ['-shared']
LINKFLAGS_cstlib = ['-Wl,-Bstatic']
LINKFLAGS_fcshlib = ['-shared']
LINK_CC = ['/usr/bin/gcc']
LINK_FC = ['/usr/bin/gfortran']
PLG = ['rel2015']
PLG_rel2015_DATA = ['tsz_143_eps0.50.dat', 'sz_x_cib_template.dat', 'ksz_fromcamspec.dat', 'cib_1h_2h_100_353_Jsr-1_PS_2014_09.dat', 'sky_template_v15_F100_143_217_353.dat', 'cnoise_F100_143_217_353_v17.dat']
PLG_rel2015_PYTHON = ['rel2015.pyx']
PLG_rel2015_SRC = ['fg2015.c', 'corrnoise.c', 'leakage.c']
PREFIX = '/user/ninastei/CCR/plc-2.0'
PYC = 1
PYFLAGS = ''
PYFLAGS_OPT = '-O'
PYO = 1
PYTHON = ['/usr/bin/python']
PYTHONARCHDIR = '/usr/lib64/python2.7/site-packages'
PYTHONDIR = '/user/ninastei/CCR/plc-2.0/lib/python2.7/site-packages'
PYTHON_CONFIG = ['/usr/bin/python-config']
PYTHON_VERSION = '2.7'
RPATH = ['/user/ninastei/CCR/plc-2.0/lib']
RPATH_ST = '-Wl,-rpath,%s'
RPATH_cfitsio = ['/user/ninastei/CCR/plc-2.0/lib']
RPATH_fc_runtime = ['/user/ninastei/CCR/plc-2.0']
RPATH_lapack = []
SHLIB_MARKER = '-Wl,-Bdynamic'
SONAME_ST = '-Wl,-h,%s'
STLIBPATH_ST = '-L%s'
STLIB_MARKER = '-Wl,-Bstatic'
STLIB_ST = '-l%s'
cprogram_PATTERN = '%s'
cshlib_PATTERN = 'lib%s.so'
cstlib_PATTERN = 'lib%s.a'
define_key = ['PYTHONDIR', 'PYTHONARCHDIR', 'HAVE_PYEMBED', 'HAVE_PYTHON_H', 'PYTHONDIR="/usr/lib/python2.7/site-packages"', 'PYTHONARCHDIR="/usr/lib64/python2.7/site-packages"', 'HAVE_PYTHON_H=1', 'HAVE_DPOSV', 'HAVE_DTRSV', 'HAVE_DPOTRF', 'HAVE_DPOTRS', 'HAVE_DPOTRI', 'HAVE_DTRTRI', 'HAVE_DTRMM', 'HAVE_DTRMV', 'HAVE_DGEQRF', 'HAVE_DORMQR', 'HAVE_DSYEV', 'HAVE_DGESVD', 'HAVE_DSYMV', 'HAVE_DGEMV', 'HAVE_DGEMM', 'HAVE_DSYRK', 'HAVE_DSYR2K', 'HAVE_DAXPY', 'HAVE_DTRSM', 'HAVE_DSYMM', 'HAVE_DSYR', 'HAVE_DDOT', 'HAVE_DSYEVD', 'HAVE_DLAMCH', 'HAVE_DSYEVR', 'HAVE_FITS_INIT_CFITSIO']
fcshlib_PATTERN = 'lib%s.so'
fcstlib_PATTERN = 'lib%s.a'
has_actspt = False
has_bflike = True
has_bicep = False
has_bopix = False
has_camspec = True
has_camspec_v3 = False
has_cfitsio = 'cfitsio'
has_cmbonly = True
has_egfs = False
has_f90 = True
has_gibbs = True
has_icc = False
has_ifort = False
has_lapack = 'lapack'
has_lenslike = True
has_lollipop = False
has_lowlike = True
has_mspec = False
has_plik = True
has_pmc = False
localpref = '/user/ninastei/CCR/plc-2.0'
macbundle_PATTERN = '%s.bundle'
mopt = '-m64'
mprefix = '/user/ninastei/CCR/plc-2.0'
plik_release = True
pyext_PATTERN = '%s.so'
shsuffix = 'so'
silent_pmc = True
svnversion = '723c1a4b0580\n\n'
use_cfitsio = 'cfitsio'
use_lapack = 'lapack'
