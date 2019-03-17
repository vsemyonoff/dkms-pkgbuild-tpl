# Maintainer: Vladislav Semyonoff <vsemyonoff@gmail.com>
# Contributor: Vladislav Semyonoff <vsemyonoff@gmail.com>

_module=example
_module_path=
_pkgname=${_module}
pkgname=${_pkgname}-dkms

pkgver=0.0.1
pkgrel=1

arch=('any')
pkgdesc="Example Loadable Kernel Modules"
url="https://github.com/vsemyonoff/dkms-pkgbuild-tpl"
license=('GPL2')

conflicts=("${_pkgname}")
depends=('dkms')
#makedepends=('git')

install=package.install

#source=("git+https://github.com/user/${_pkgname}#branch=master" "dkms.conf")
source=("Makefile" "${_module}.c" "dkms.conf")

sha256sums=('SKIP' 'SKIP' 'SKIP')

package() {
  # Copy files
  install -dm755 "${pkgdir}"/usr/src/${_pkgname}-${pkgver}
  install -Dm644 {Makefile,${_module}.c,dkms.conf} "${pkgdir}"/usr/src/${_pkgname}-${pkgver}/

  # Set name and version
  sed -e "s/@MODULE@/${_module}/" \
      -e "s|@MODULE_PATH@|${_module_path}|" \
      -e "s/@PKGNAME@/${_pkgname}/" \
      -e "s/@PKGVER@/${pkgver}/" \
      -i "${pkgdir}"/usr/src/${_pkgname}-${pkgver}/dkms.conf

  ## Copy sources (including Makefile)
  #cp -dr --no-preserve='ownership' ${_pkgname}/* "${pkgdir}/usr/src/${_pkgname}-${pkgver}/"

  ## Override module dependency for patched modules from mainline
  #echo "override ${_module} 5.0.* updates/${_module_path}" |
  #    install -Dm644 /dev/stdin "${pkgdir}/etc/depmod.d/${_pkgname}-5.0.conf"
}
