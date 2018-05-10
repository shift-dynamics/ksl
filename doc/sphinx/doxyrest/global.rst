.. _global-namespace:

Global Namespace
================

.. index:: pair: namespace; global

.. toctree::
	:hidden:

	enum_ksl_axis_enum_t.rst
	union_ksl_SE3_t.rst
	union_ksl_SE3f_t.rst
	union_ksl_coscrew_t.rst
	union_ksl_coscrewf_t.rst
	union_ksl_inertia_t.rst
	union_ksl_inertiaf_t.rst
	union_ksl_mat3x3_t.rst
	union_ksl_mat3x3f_t.rst
	union_ksl_mat4x4_t.rst
	union_ksl_mat4x4f_t.rst
	union_ksl_quaternion_t.rst
	union_ksl_quaternionf_t.rst
	union_ksl_screw_t.rst
	union_ksl_screwf_t.rst
	union_ksl_vec3_t.rst
	union_ksl_vec3f_t.rst
	union_ksl_vec3i_t.rst
	union_ksl_vec4_t.rst
	union_ksl_vec4f_t.rst



Overview
~~~~~~~~



.. _doxid-axis_8h_1ad6073885fe924b7021988bab4a48d7aa:
.. _cid-ksl_axis_enumfromchar:
.. _doxid-coscrew_8h_1ac0fdd65a2771c4b193ed3fc3945a016d:
.. _cid-ksl_cross_cc:
.. _doxid-coscrew_8h_1aa8ed6483191adc2df6a8985d21e92134:
.. _cid-ksl_cross_ccf:
.. _doxid-coscrew_8h_1ae91994ff97f0e66afef7d7f209b3eab3:
.. _cid-ksl_product_coadtc:
.. _doxid-coscrew_8h_1ae405e0975ccab056994c76d9196ca661:
.. _cid-ksl_product_coadtcf:
.. _doxid-coscrew_8h_1a3348760a0fb25baa668a9f816effbda9:
.. _cid-ksl_product_coadtcinv:
.. _doxid-coscrew_8h_1a40003bacac2a7a4d95ceb351a2642272:
.. _cid-ksl_product_coadtcinvf:
.. _doxid-coscrew_8h_1a1b2e57285d1503ae6a06486b3756ee75:
.. _cid-ksl_product_coadc:
.. _doxid-coscrew_8h_1a85a14ad142e8e32305a46d011d07a533:
.. _cid-ksl_product_coadcf:
.. _doxid-coscrew_8h_1a56fc0dd60484c8e65e0ed39c2e0aaf53:
.. _cid-ksl_product_coadinvc:
.. _doxid-coscrew_8h_1a694ab10025f55a0d1c7ce0e4b59b1ef7:
.. _cid-ksl_product_coadinvcf:
.. _doxid-inertia_8h_1af0cd32160b2e02005aafd7ac2f28c7fd:
.. _cid-ksl_inertia_alloc:
.. _doxid-inertia_8h_1a874d1323b8d541d7d95ef685277b95a3:
.. _cid-ksl_inertiaf_alloc:
.. _doxid-inertia_8h_1a4a387d0c872abcabf269273ba58db901:
.. _cid-ksl_inertia_rotated:
.. _doxid-inertia_8h_1a1a1e3f03ccf343e0bbae6cf5b5057bf9:
.. _cid-ksl_inertiaf_rotated:
.. _doxid-inertia_8h_1a5143ef0a4aa1f7a701d28388aa8cf1e1:
.. _cid-ksl_inertia_rotate:
.. _doxid-inertia_8h_1a095683dadc83becbf6160d84888bdbd8:
.. _cid-ksl_inertiaf_rotate:
.. _doxid-inertia_8h_1a0ffd6ef04f8f7abb2901d45fd22daf63:
.. _cid-ksl_inertia_translated:
.. _doxid-inertia_8h_1a073ce8555bd68566833b2b7ef95e181e:
.. _cid-ksl_inertiaf_translated:
.. _doxid-inertia_8h_1a05c6d53f909791b8796bbb4fe909a789:
.. _cid-ksl_inertia_translate:
.. _doxid-inertia_8h_1a896b52736acad0b43b06d61fac55b99f:
.. _cid-ksl_inertiaf_translate:
.. _doxid-inertia_8h_1a2e0ddd09114d6e78d0395419dac7d51d:
.. _cid-ksl_inertia_transformed:
.. _doxid-inertia_8h_1adcaf2a48154f2ab93b1c88fb0a655992:
.. _cid-ksl_inertiaf_transformed:
.. _doxid-inertia_8h_1aaa8803a3a2c64f1c85035bb525c1db63:
.. _cid-ksl_inertia_merge:
.. _doxid-inertia_8h_1ad2a5726ed9a42f28903084ae99eac1ca:
.. _cid-ksl_inertiaf_merge:
.. _doxid-inertia_8h_1a4d826f10adde0189c80e4018a4114ab2:
.. _cid-ksl_inertia_factor:
.. _doxid-linalg_8h_1a39fe7ed1c9c5d79e9b853a5c896b5f81:
.. _cid-ksl_linalg_gramschmidt:
.. _doxid-linalg_8h_1a847ae66e3fdbb96c2dfd1907d7e9321b:
.. _cid-ksl_linalg_pca:
.. _doxid-linalg_8h_1a489b07a456ecff304b9248378bdb2246:
.. _cid-ksl_swaparray:
.. _doxid-linalg_8h_1ada2b2790c0d9e02ecfa08a1761ef34bc:
.. _cid-ksl_maxindex:
.. _doxid-linalg_8h_1a6885b2843d4b08e01fb9fe30285b62b4:
.. _cid-ksl_linalg_lu:
.. _doxid-linalg_8h_1a69364d153f034d3039c51e4667f36bcc:
.. _cid-ksl_linalg_lu_backwardsubstitution:
.. _doxid-linalg_8h_1a027e24833df3b9e2d9ac1fd40f4e3be2:
.. _cid-ksl_linalg_lu_forwardsubstitution:
.. _doxid-linalg_8h_1a2fb85ffd2c3a5feaf5113090bf96ddb1:
.. _cid-ksl_linalg_lu_solve:
.. _doxid-linalg_8h_1a8f4fbd129dbfb82933885a6b080c1cc7:
.. _cid-ksl_linalg_lu_full:
.. _doxid-linalg_8h_1a44bd8db3b9ddaa42def52b623addb010:
.. _cid-ksl_linalg_lu_full_specified:
.. _doxid-linalg_8h_1aca63564a845bfa0be61c09a66bb21aae:
.. _cid-ksl_linalg_lu_full_backwardsubstitution:
.. _doxid-linalg_8h_1a00da5d1bf01273836109fe3df3d6ccb2:
.. _cid-ksl_linalg_lu_full_forwardsubstitution:
.. _doxid-linalg_8h_1af3790792026239c7c30914d5c6a9bd98:
.. _cid-ksl_linalg_lu_full_solve:
.. _doxid-linalg_8h_1a88931f7781fab67dfa648171cce3bf09:
.. _cid-ksl_linalg_lu_setbmatrix:
.. _doxid-linalg_8h_1a33cdaccb302aea42be830d41c16fef0d:
.. _cid-ksl_linalg_ldlt:
.. _doxid-linalg_8h_1a841165f4173bc0d325874b9e090e1617:
.. _cid-ksl_linalg_ldlt_backwardsubstitution:
.. _doxid-linalg_8h_1a33ff094bb8525e7e6760211eff36dcc7:
.. _cid-ksl_linalg_ldlt_forwardsubstitution:
.. _doxid-linalg_8h_1a30e770ffc35662baf4768686891faaf1:
.. _cid-ksl_linalg_ldlt_solve:
.. _doxid-linalg_8h_1ace4fcd62dade22eeba17574d159f2e4f:
.. _cid-ksl_linalg_cholesky:
.. _doxid-linalg_8h_1a3a6b1eb40bb072207d28ef2a35dd0fdc:
.. _cid-ksl_linalg_cholesky_forwardsubstitution:
.. _doxid-linalg_8h_1a4966ac319ce718c032d362ed04f0a4d1:
.. _cid-ksl_linalg_cholesky_backwardsubstitution:
.. _doxid-linalg_8h_1a17fcec5a36f080b904f2d1331d93eed7:
.. _cid-ksl_linalg_cholesky_solve:
.. _doxid-linalg_8h_1af72c21187b1010d61986e837cb6d338c:
.. _cid-ksl_linalg_symmetricmatrixinverse:
.. _doxid-matrix_8h_1aa23106f34ee002c1ec4dc48540022db9:
.. _cid-ksl_se3_alloc:
.. _doxid-matrix_8h_1a5673106ac00d2f4dd02bc18bf1d099aa:
.. _cid-ksl_se3f_alloc:
.. _doxid-matrix_8h_1a177a3af999c2239620defafa6b1e4f0d:
.. _cid-ksl_mat3x3_alloc:
.. _doxid-matrix_8h_1a22d340236febac390dd4e91444bedb7a:
.. _cid-ksl_mat3x3f_alloc:
.. _doxid-matrix_8h_1af1b547addbeec4c69de1c288f4ab6f87:
.. _cid-ksl_mat4x4_alloc:
.. _doxid-matrix_8h_1a70aecea12480d41931a254396cb2dcd9:
.. _cid-ksl_mat4x4f_alloc:
.. _doxid-matrix_8h_1abe0d938eae89c1165e49792df6320f5c:
.. _cid-ksl_se3_tomat4x4:
.. _doxid-matrix_8h_1ab752ddf0d405c49c8217cfca6aeab93c:
.. _cid-ksl_se3f_tomat4x4f:
.. _doxid-matrix_8h_1ace3abb7ded8d1a7a3068ab36faf23fa6:
.. _cid-ksl_se3_tomat4x4f:
.. _doxid-matrix_8h_1aabbc12342b5548399e0b1d09bc2a28c8:
.. _cid-ksl_dc:
.. _doxid-matrix_8h_1a1e586c05382ebb177e18490fba4f738c:
.. _cid-ksl_se3_setidentity:
.. _doxid-matrix_8h_1add2f0dbc6d29b0b1695100a262d8ca69:
.. _cid-ksl_se3f_setidentity:
.. _doxid-matrix_8h_1ab58fb659ed34589b759a9bff7257f9c0:
.. _cid-ksl_mat3x3_setidentity:
.. _doxid-matrix_8h_1a81ad7fbd8db8e8464cf7a96c8d87df09:
.. _cid-ksl_mat3x3f_setidentity:
.. _doxid-matrix_8h_1a214b4ee953af0437c415341ac20ba7c9:
.. _cid-ksl_mat3x3_set:
.. _doxid-matrix_8h_1a7e4178be19e7ab6820de2aed88a11f08:
.. _cid-ksl_mat4x4_set:
.. _doxid-matrix_8h_1ae4000f58b12ee4202a1851aebbcb4a3d:
.. _cid-ksl_se3_set:
.. _doxid-matrix_8h_1aa263ec13c47bf19dfcb646fb3ac8e40d:
.. _cid-ksl_se3f_set:
.. _doxid-matrix_8h_1a2f0629a91c545f60a49380a74ce1bf46:
.. _cid-ksl_mat3x3_setfromvectors:
.. _doxid-matrix_8h_1a826c58e7955ed694952468b334e42d79:
.. _cid-ksl_mat3x3f_set:
.. _doxid-matrix_8h_1aca485e889183d9468d741f5a1f347ed4:
.. _cid-ksl_mat4x4f_set:
.. _doxid-matrix_8h_1a1e0dc7d0fc1151b7a90d1b2b25cf7cbc:
.. _cid-ksl_mat4x4_setidentity:
.. _doxid-matrix_8h_1afba7a831dd92d569b81b9a0cdcefda83:
.. _cid-ksl_mat4x4f_setidentity:
.. _doxid-matrix_8h_1abd65fe3a5e53ee802e2dababa95c3dc4:
.. _cid-ksl_se3_get:
.. _doxid-matrix_8h_1a83192ca3ace3ddb96906cf0ec071cc86:
.. _cid-ksl_mat3x3_get:
.. _doxid-matrix_8h_1a7e9dfa7888842a24a24805cebef9459e:
.. _cid-ksl_mat3x3f_get:
.. _doxid-matrix_8h_1ac1a8a1a5bab85a4c524449e00e5e00e1:
.. _cid-ksl_se3f_get:
.. _doxid-matrix_8h_1a8154daa30091f68b1ffb62e2a3cb70a1:
.. _cid-ksl_se3_gettranslation:
.. _doxid-matrix_8h_1a659e01255e0bc4624033464e2e7182ca:
.. _cid-ksl_mat3x3_copy:
.. _doxid-matrix_8h_1a0008a609192b6e2e9019d3634b15f6ad:
.. _cid-ksl_mat3x3f_copy:
.. _doxid-matrix_8h_1acf0aab81ac6a7f759f5f4f6ac6e7dad8:
.. _cid-ksl_mat3x3_invert:
.. _doxid-matrix_8h_1a6735899de6d44a28d0e304b6fd940546:
.. _cid-ksl_mat3x3_inverted:
.. _doxid-matrix_8h_1a264c29f922f7813d256773dcc33b3138:
.. _cid-ksl_mat3x3_transpose:
.. _doxid-matrix_8h_1aa6d90d88f07f34c037e3f846b5de8271:
.. _cid-ksl_mat3x3f_transpose:
.. _doxid-matrix_8h_1a4fa0f7ec6a937a375afdb9865574fecc:
.. _cid-ksl_mat3x3_transposed:
.. _doxid-matrix_8h_1aa5574ade523fa581161cfc09b5204a05:
.. _cid-ksl_mat3x3f_transposed:
.. _doxid-matrix_8h_1aca804b2c785d9f036446df45beababae:
.. _cid-ksl_se3_invert:
.. _doxid-matrix_8h_1ac05052c4b6660087dc45c399a1bf498d:
.. _cid-ksl_se3f_invert:
.. _doxid-matrix_8h_1a1bb0f88b0a2aa12c88364e10817a6374:
.. _cid-ksl_se3_inverted:
.. _doxid-matrix_8h_1a883d826184c26412ceddfab0f5bc97a4:
.. _cid-ksl_se3f_inverted:
.. _doxid-matrix_8h_1ad872da8f3834ab436e0388de6134fd2f:
.. _cid-ksl_se3_copy:
.. _doxid-matrix_8h_1a182b96d3aaed5e6ba17eb15748dd7a1a:
.. _cid-ksl_se3f_copy:
.. _doxid-matrix_8h_1aec5ee51720d1b8ed92bc7a9678f18564:
.. _cid-ksl_mat3x3_geteulerangles:
.. _doxid-matrix_8h_1a54df1c5eb6cf4d6c450e76c614b8bb3d:
.. _cid-ksl_mat3x3_setfromeulerangles:
.. _doxid-matrix_8h_1ac0234439a7cbd6d0ec58bb2542e50d60:
.. _cid-ksl_mat3x3_getscalar:
.. _doxid-matrix_8h_1a1eb8b085bf98243f5fd9cea178b9349f:
.. _cid-ksl_mat3x3f_getscalar:
.. _doxid-matrix_8h_1a21b4e9dad800701badf4a4ae20e9e888:
.. _cid-ksl_mat3x3_getaxisangle:
.. _doxid-matrix_8h_1a655d343e8889959a198bd3055c8c0d7c:
.. _cid-ksl_mat4x4_gettranslation:
.. _doxid-matrix_8h_1a2d6b59053e391cf62311fcb6bf71081d:
.. _cid-ksl_mat4x4f_gettranslation:
.. _doxid-matrix_8h_1ab9d90e415397b467f5fbf24d63593913:
.. _cid-ksl_mat4x4_get:
.. _doxid-matrix_8h_1aaacb3f73b5db33f0259007ea185d6a22:
.. _cid-ksl_mat4x4f_get:
.. _doxid-matrix_8h_1a9c6c8a3db26680b4aa525c5253a950ee:
.. _cid-ksl_mat3x3_determinant:
.. _doxid-matrix_8h_1a403d3115123b4f76a6f27ec5ca7ce274:
.. _cid-ksl_product_drv:
.. _doxid-matrix_8h_1aecf5aac9412aa19ae834d319ebd98ea5:
.. _cid-ksl_product_drvf:
.. _doxid-matrix_8h_1a5b7eee293303e16c8231e8afefcbd264:
.. _cid-ksl_product_drvinv:
.. _doxid-matrix_8h_1aafcb94ac1cdfccb9971afbe83469ee48:
.. _cid-ksl_product_drvinvf:
.. _doxid-matrix_8h_1a6f03fffadeea016f79b189a676ef6590:
.. _cid-ksl_product_drinvv:
.. _doxid-matrix_8h_1aa4c9340e1679402e966641529aef2dd5:
.. _cid-ksl_product_drinvvf:
.. _doxid-matrix_8h_1a512dbc30bc144e22d84b0ebcb467ee99:
.. _cid-ksl_product_drinvvinv:
.. _doxid-matrix_8h_1acfca5a948a1b891c67fbabe61afb4f82:
.. _cid-ksl_product_drinvvinvf:
.. _doxid-matrix_8h_1a74533c22448aa1778ff734d287931ff5:
.. _cid-ksl_product_drvtx:
.. _doxid-matrix_8h_1a895ddfe07eb888ed3d287a6da0d21b98:
.. _cid-ksl_product_drvtxf:
.. _doxid-matrix_8h_1ac6c6d0870043eae9ac8d21170ac0f35e:
.. _cid-ksl_product_drvtxinv:
.. _doxid-matrix_8h_1a20e95b864ae594011833dc0b2d58bb33:
.. _cid-ksl_product_drvtxinvf:
.. _doxid-matrix_8h_1a77fc0964e58b852eb9849fdc98500853:
.. _cid-ksl_product_drvty:
.. _doxid-matrix_8h_1adaed020b38a6b59f2b3ca909b134ab33:
.. _cid-ksl_product_drvtyf:
.. _doxid-matrix_8h_1af0db5c28061626299de279551fdf1448:
.. _cid-ksl_product_drvtyinv:
.. _doxid-matrix_8h_1a528e7cf7dd8657c1c16b2476c8e3180b:
.. _cid-ksl_product_drvtyinvf:
.. _doxid-matrix_8h_1a382179892501b2ca11749f8dabfff479:
.. _cid-ksl_product_drvtz:
.. _doxid-matrix_8h_1afea0117039f42f40c2f5a20cbeca8682:
.. _cid-ksl_product_drvtzf:
.. _doxid-matrix_8h_1a3c25a5ad0517dddf6459876b6a2aded7:
.. _cid-ksl_product_drvtzinv:
.. _doxid-matrix_8h_1a156424d82a2ec1821ddfa518de21fbdb:
.. _cid-ksl_product_drvtzinvf:
.. _doxid-matrix_8h_1ab28fd58fa54787c6d00e8583551f269b:
.. _cid-ksl_product_drdrx:
.. _doxid-matrix_8h_1a841e4404e3180416561d1eb85f42f752:
.. _cid-ksl_product_drdrxf:
.. _doxid-matrix_8h_1a0f8147a0eccde2ea280f9cedf0161e41:
.. _cid-ksl_product_drdrxinv:
.. _doxid-matrix_8h_1a035330469bffd88388cde0b7531b1fdd:
.. _cid-ksl_product_drdrxinvf:
.. _doxid-matrix_8h_1a42eb97c1b223820a1e6786e8c84a1cc6:
.. _cid-ksl_product_drdry:
.. _doxid-matrix_8h_1ac76d6dfd9d92929ef94bbe1a35e5ef6c:
.. _cid-ksl_product_drdryf:
.. _doxid-matrix_8h_1a7ce0d67d2bdc0d81bba7b63505a4bbaa:
.. _cid-ksl_product_drdryinv:
.. _doxid-matrix_8h_1a75538fc1a0894a5281ae9b9aa4747550:
.. _cid-ksl_product_drdryinvf:
.. _doxid-matrix_8h_1ad8de4524273920c39c60a682f59def10:
.. _cid-ksl_product_drdrz:
.. _doxid-matrix_8h_1aa1968e258d20b175fb2c51bef32862d3:
.. _cid-ksl_product_drdrzf:
.. _doxid-matrix_8h_1a63f176e05ec89befa6cae43281273888:
.. _cid-ksl_product_drdrzinv:
.. _doxid-matrix_8h_1a87876bb5e6f36dfb32832cb59cd59386:
.. _cid-ksl_product_drdrzinvf:
.. _doxid-matrix_8h_1a9909e2688e96649fc489d4146cf76309:
.. _cid-ksl_product_drdr:
.. _doxid-matrix_8h_1a4a10bf67a02e33862201f67be3d1e306:
.. _cid-ksl_product_drdrf:
.. _doxid-matrix_8h_1a8ab8a0fa93f7904f1383a2bd1c43d383:
.. _cid-ksl_product_drdrinv:
.. _doxid-matrix_8h_1a61401166bb323fb690f17fb057b3fabc:
.. _cid-ksl_product_drdrinvf:
.. _doxid-matrix_8h_1ac7c3eb3a0a483c04849d5400f83346f7:
.. _cid-ksl_product_drinvdr:
.. _doxid-matrix_8h_1afdc3dbfcdeb378dee0d302a95ed1878e:
.. _cid-ksl_product_drinvdrf:
.. _doxid-matrix_8h_1a89cbbe54e33d39734fad9eaf019938c1:
.. _cid-ksl_product_dv:
.. _doxid-matrix_8h_1a4fd6871e4bd4853ddb181bc77f40db5c:
.. _cid-ksl_product_dinvv:
.. _doxid-matrix_8h_1a89fbbfddfa9b023c8bf59dce0f515ee6:
.. _cid-ksl_product_ddrx:
.. _doxid-matrix_8h_1a9cc272be249bbf2610fedf23f70f5b7d:
.. _cid-ksl_product_ddrxf:
.. _doxid-matrix_8h_1af0fe4b62b1ae13c590bec8be64771d78:
.. _cid-ksl_product_ddrxinv:
.. _doxid-matrix_8h_1a95c46420eca8e31fcd7b76d41fe1143f:
.. _cid-ksl_product_ddrxinvf:
.. _doxid-matrix_8h_1a954264c1bc3a4e8e47e63c2682bb9090:
.. _cid-ksl_product_ddry:
.. _doxid-matrix_8h_1a4302352cde9ca58fa87f55d93996fe9a:
.. _cid-ksl_product_ddryf:
.. _doxid-matrix_8h_1afd619afd47692e36a9cad186fee6b687:
.. _cid-ksl_product_ddryinv:
.. _doxid-matrix_8h_1ac26fbb7270a979e832ca699ce627644b:
.. _cid-ksl_product_ddryinvf:
.. _doxid-matrix_8h_1a904407cfe285833aa9f070cc55e7a56e:
.. _cid-ksl_product_ddrz:
.. _doxid-matrix_8h_1af2a48c5e14b9e2ce6a6c4d77d2dbffac:
.. _cid-ksl_product_ddrzf:
.. _doxid-matrix_8h_1ad08885ba5969c6662ce36aeec35e0680:
.. _cid-ksl_product_ddrzinv:
.. _doxid-matrix_8h_1a2d1255d8074162eef6a5a3a8f2f8284d:
.. _cid-ksl_product_ddrzinvf:
.. _doxid-matrix_8h_1ada7fc5c86c16b78c6c11c98861001d60:
.. _cid-ksl_product_ddt:
.. _doxid-matrix_8h_1a9fe2fb618bf2b59cba070eae4e6e1df2:
.. _cid-ksl_product_ddtinv:
.. _doxid-matrix_8h_1a27b001c3020cbedebacb8498b3e03a0e:
.. _cid-ksl_product_ddtf:
.. _doxid-matrix_8h_1a2010a2f24e1da281d83db9f9f9e583cb:
.. _cid-ksl_product_dinvdt:
.. _doxid-matrix_8h_1a1784236b926c17bf09e0ab65c2869585:
.. _cid-ksl_product_dinvdtf:
.. _doxid-matrix_8h_1a7efab3193f502c06f891011536e129dd:
.. _cid-ksl_product_ddtx:
.. _doxid-matrix_8h_1a3fabcec659331aa080eeff02bb77a195:
.. _cid-ksl_product_ddtxinv:
.. _doxid-matrix_8h_1a49c127a19375005dd3dcf0db8a5f154c:
.. _cid-ksl_product_ddtxinvf:
.. _doxid-matrix_8h_1a868400ded32600cc2e983dbc9eb701c1:
.. _cid-ksl_product_ddty:
.. _doxid-matrix_8h_1a7ee9767dfdf20e08d8b1128643d3b8c0:
.. _cid-ksl_product_ddtyf:
.. _doxid-matrix_8h_1a2d309b34086fe456701e99053a5fa5d5:
.. _cid-ksl_product_ddtyinv:
.. _doxid-matrix_8h_1a737c7b541ba23d0f3fc924115a04b646:
.. _cid-ksl_product_ddtyinvf:
.. _doxid-matrix_8h_1ad2ee354edcf8f508911f9626c042a8f5:
.. _cid-ksl_product_ddtz:
.. _doxid-matrix_8h_1afce7b27ccf0cdbdb464d4dde33de0925:
.. _cid-ksl_product_ddtzf:
.. _doxid-matrix_8h_1a788d88150cac3e051989b2ec9136890d:
.. _cid-ksl_product_ddtzinv:
.. _doxid-matrix_8h_1aa9c8e7bdfb33c1bf5399056e863a43a5:
.. _cid-ksl_product_ddr:
.. _doxid-matrix_8h_1af902cbe4b9c0e2747f285607e352cc92:
.. _cid-ksl_product_ddrf:
.. _doxid-matrix_8h_1a4539c07a76339e8f140dbb84e26fe60d:
.. _cid-ksl_product_ddrinv:
.. _doxid-matrix_8h_1a5cd6901393ac24ac3926834a39ef8d52:
.. _cid-ksl_product_ddrinvf:
.. _doxid-matrix_8h_1a15bcf0d47792c422bf2a37776d8fedf1:
.. _cid-ksl_product_dd:
.. _doxid-matrix_8h_1af3efc7b072d4ee61ec9e32934a567a52:
.. _cid-ksl_product_ddf:
.. _doxid-matrix_8h_1a0212b856cf24880d5a12f019dfee91bc:
.. _cid-ksl_product_ddinv:
.. _doxid-matrix_8h_1aa551d477178695b29bd4732f0cf8f3f8:
.. _cid-ksl_product_ddinvf:
.. _doxid-print_8h_1a9270fa1f856257499ffd87990ce9ab7a:
.. _cid-ksl_vec3_print:
.. _doxid-print_8h_1a4ada72a9f6d5232a96d5ec6c05153aa0:
.. _cid-ksl_vec3f_print:
.. _doxid-print_8h_1afeebd4fa2c48bae3bf3444adc3ea34de:
.. _cid-ksl_quaternion_print:
.. _doxid-print_8h_1a3c555d30f03e8888f2d036b5e3d9db03:
.. _cid-ksl_quaternionf_print:
.. _doxid-print_8h_1ab1b8560d133e4917d9a2d4de48cd785c:
.. _cid-ksl_screw_print:
.. _doxid-print_8h_1a6607104727060794c6449fcffd20d1ff:
.. _cid-ksl_screwf_print:
.. _doxid-print_8h_1a4d09c4103b219631d5fec42cdd7d8247:
.. _cid-ksl_mat3x3_print:
.. _doxid-print_8h_1a79ca08255ff03cbd88d3956e92f5c97b:
.. _cid-ksl_mat3x3f_print:
.. _doxid-print_8h_1ab5a8813219ea6d80efac895ea3aea481:
.. _cid-ksl_se3_print:
.. _doxid-print_8h_1a3e1faa03e7ba0529048eb6aa0d5a9ceb:
.. _cid-ksl_mat4x4_print:
.. _doxid-print_8h_1a75d4da21f97f12e1d00520415dc10f1c:
.. _cid-ksl_mat4x4f_print:
.. _doxid-print_8h_1ac87fcb01c3bb059de808d00871be7c92:
.. _cid-ksl_array_print:
.. _doxid-print_8h_1aa285af90ee02264ddadf3b0a30af019b:
.. _cid-ksl_array_print2d:
.. _doxid-print_8h_1a1619bebc0d5a27e491a56b91a1b5b61e:
.. _cid-ksl_arrayi_print:
.. _doxid-print_8h_1aaf22a9dfbe9844c4cd12ed76ae3564af:
.. _cid-ksl_triang_print:
.. _doxid-print_8h_1a57726dad195b08744cb4653cf33a3868:
.. _cid-ksl_triangi_print:
.. _doxid-print_8h_1a9bce14a055967c1d396aeb8ad70d149a:
.. _cid-ksl_triangb_print:
.. _doxid-print_8h_1af2ce2f18aedfd81cef6e1a8849632507:
.. _cid-ksl_inertia_print:
.. _doxid-quaternion_8h_1ae75cd05add834eba87be79a742012dd5:
.. _cid-ksl_quaternion_dot_qq:
.. _doxid-quaternion_8h_1a00abc36c85fc1bc05511087434c6dffc:
.. _cid-ksl_dot_qqf:
.. _doxid-quaternion_8h_1a4bbc6173c3c16a92f0523d819f977a2b:
.. _cid-ksl_quaternion_normalize:
.. _doxid-quaternion_8h_1aa783cae3b763b7ad7c1729597796f5ec:
.. _cid-ksl_quaternionf_normalize:
.. _doxid-quaternion_8h_1a8889ecf28d046592ee43aba899111dff:
.. _cid-ksl_axpy_qq:
.. _doxid-quaternion_8h_1a260211df497b9280c537711aafb7fa11:
.. _cid-ksl_axpy_qqf:
.. _doxid-quaternion_8h_1a4b7837422501e29fda0aaf5243071b08:
.. _cid-ksl_mat3x3_toquaternion:
.. _doxid-quaternion_8h_1af6cea8a3c4baa179c6e0e804a965ebeb:
.. _cid-ksl_mat3x3f_toquaternion:
.. _doxid-quaternion_8h_1a51a0f6ba1626ccbaa6265511b08a610b:
.. _cid-ksl_quaternion_tomat3x3:
.. _doxid-quaternion_8h_1aa1077ff08a015743fb8bebf7d5c285dd:
.. _cid-ksl_quaternionf_tomat3x3f:
.. _doxid-quaternion_8h_1a2c6b411fbf4d63125b75e1f8765600c6:
.. _cid-ksl_quaternion_slerp:
.. _doxid-quaternion_8h_1a567a7b9d042f3384ede44ba4a55be11e:
.. _cid-ksl_slerpf:
.. _doxid-quaternion_8h_1aad8c5163fd6dfa6a50c64c41640e2b97:
.. _cid-ksl_quaternion_squad:
.. _doxid-quaternion_8h_1acb4eadfbd498c7f810d46992f8e30b8e:
.. _cid-ksl_squadf:
.. _doxid-quaternion_8h_1aa40fc32e961e0ad916147221619e9138:
.. _cid-ksl_quaternion_nlerp:
.. _doxid-quaternion_8h_1af730b86ef9792fe0f5f5b53365ee14b4:
.. _cid-ksl_nlerpf:
.. _doxid-quaternion_8h_1aaf557c10cb9f46b17cad760a48b54e6e:
.. _cid-ksl_add_dpitoq:
.. _doxid-quaternion_8h_1a7b657dcaae73668c4ff2db2c41f77e82:
.. _cid-ksl_subtract_dpifromq:
.. _doxid-quaternion_8h_1a8a0f4919ffea92dfff629d5fb6be1868:
.. _cid-ksl_omega_to_dquaternion:
.. _doxid-quaternion_8h_1abc26349b8d60db57d7c730a20139b640:
.. _cid-ksl_quaternion_product_qq:
.. _doxid-quaternion_8h_1a4a31b644d84597160d0477e897ad3379:
.. _cid-ksl_product_qqf:
.. _doxid-quaternion_8h_1ae683751d417423f14e6e2dc972cdf14f:
.. _cid-ksl_quaternion_product_qconjq:
.. _doxid-quaternion_8h_1a5403e09193edb3fdd6523fb3b0b6d98e:
.. _cid-ksl_product_qconjqf:
.. _doxid-quaternion_8h_1a1af116cdbf7e169b9d9fc5d6b063274e:
.. _cid-ksl_quaternion_product_qqconj:
.. _doxid-quaternion_8h_1a45025779e2ae39968c12f45438e576b5:
.. _cid-ksl_product_qqconjf:
.. _doxid-quaternion_8h_1aaa90d090c870bba71f84ba8164d9e91b:
.. _cid-ksl_quaternion_product_qconjqconj:
.. _doxid-quaternion_8h_1abfa97ee7824eccb3386e20e6c8fafc15:
.. _cid-ksl_product_qconjqconjf:
.. _doxid-quaternion_8h_1afbb297e07ab17e4d91ac72f949aa1811:
.. _cid-ksl_quaternion_product_qxq:
.. _doxid-quaternion_8h_1abfa36912c5534b816a3b1d9ff2283ff4:
.. _cid-ksl_product_qxqf:
.. _doxid-quaternion_8h_1aaff6b2c39d8b6ad18292841597303401:
.. _cid-ksl_quaternion_product_qqx:
.. _doxid-quaternion_8h_1ae49d64ebcb2578576be06dcb83095da3:
.. _cid-ksl_product_qqxf:
.. _doxid-quaternion_8h_1acbf7ec3f2622f876932d4c9bf4569572:
.. _cid-ksl_quaternion_product_qxconjq:
.. _doxid-quaternion_8h_1ad220ee3e8ab99605cdd4daaf4f5ad234:
.. _cid-ksl_product_qxconjqf:
.. _doxid-quaternion_8h_1a21ed20c4c20713bb4c6448c3cd2156f1:
.. _cid-ksl_quaternion_product_qconjqx:
.. _doxid-quaternion_8h_1a256112caff02b3314b4d1847a796f78c:
.. _cid-ksl_product_qconjqxf:
.. _doxid-quaternion_8h_1aad0e55be21c68bfdc09ec2a420d7b869:
.. _cid-ksl_quaternion_product_qxqconj:
.. _doxid-quaternion_8h_1aa6ce3de04c6ce9680f56378ca0559e89:
.. _cid-ksl_product_qxqconjf:
.. _doxid-quaternion_8h_1ac30d15c38e41cf9ded9ce91926b2ba97:
.. _cid-ksl_quaternion_product_qqxconj:
.. _doxid-quaternion_8h_1a95d2c245a7197ad923440f9823cc727f:
.. _cid-ksl_product_qqxconjf:
.. _doxid-quaternion_8h_1a5606a41ed5280c9174b4f57661028a25:
.. _cid-ksl_quaternion_product_qxconjqconj:
.. _doxid-quaternion_8h_1af123d8fc30bba0fe8149d42492581b6c:
.. _cid-ksl_product_qxconjqconjf:
.. _doxid-quaternion_8h_1a2d5e050d270edd9f40f07f8654a550e2:
.. _cid-ksl_quaternion_product_qconjqxconj:
.. _doxid-quaternion_8h_1ab087ea4f0692a134d877c85f0e046c70:
.. _cid-ksl_product_qconjqxconjf:
.. _doxid-quaternion_8h_1ae03e895cee11516cc2ae35d6b054ac1b:
.. _cid-ksl_quaternion_product_qyq:
.. _doxid-quaternion_8h_1a41cd03f11c445cbea1c9a6dd88216a23:
.. _cid-ksl_product_qyqf:
.. _doxid-quaternion_8h_1a428a7ff0a4d289edc8742f84f4523d05:
.. _cid-ksl_quaternion_product_qqy:
.. _doxid-quaternion_8h_1a79fb98bb9a24d0d8c6d41549ee7013ff:
.. _cid-ksl_product_qqyf:
.. _doxid-quaternion_8h_1aa1a853ab2ffc10904b601dc95f626639:
.. _cid-ksl_quaternion_product_qyconjq:
.. _doxid-quaternion_8h_1acd9f145e0d78093132271d2598c080ff:
.. _cid-ksl_product_qyconjqf:
.. _doxid-quaternion_8h_1add4fe8f41a26de55f96d582483899e2e:
.. _cid-ksl_quaternion_product_qconjqy:
.. _doxid-quaternion_8h_1ac964a285496869a1794b108b89693d1a:
.. _cid-ksl_product_qconjqyf:
.. _doxid-quaternion_8h_1a98298917de1b2a964cf79801524c0ab7:
.. _cid-ksl_quaternion_product_qyqconj:
.. _doxid-quaternion_8h_1adae2c17ccf714c25a97d2b95bab1c62e:
.. _cid-ksl_product_qyqconjf:
.. _doxid-quaternion_8h_1a43d0de9befe25e9595fd7dcfb5a7aa0e:
.. _cid-ksl_quaternion_product_qqyconj:
.. _doxid-quaternion_8h_1aca2454eeaae4915834900c10b2979d9d:
.. _cid-ksl_product_qqyconjf:
.. _doxid-quaternion_8h_1a1f167b9e8a2fee613008d574844f7640:
.. _cid-ksl_quaternion_product_qyconjqconj:
.. _doxid-quaternion_8h_1aba415d59b87767ca8ec14935e2e22eda:
.. _cid-ksl_product_qyconjqconjf:
.. _doxid-quaternion_8h_1a5c6afaf16cd1a3e97c690ff3bbb6d8f9:
.. _cid-ksl_quaternion_product_qconjqyconj:
.. _doxid-quaternion_8h_1a707dbdf400f2bd7767f3be7a8753fad0:
.. _cid-ksl_product_qconjqyconjf:
.. _doxid-quaternion_8h_1a23f492191678f6fa774585bc4f9739f7:
.. _cid-ksl_quaternion_product_qzq:
.. _doxid-quaternion_8h_1a1fcabdc2a8877ce55184be2edbf7a3a2:
.. _cid-ksl_product_qzqf:
.. _doxid-quaternion_8h_1a2d302d106801a2aa0a32125a26c8d098:
.. _cid-ksl_quaternion_product_qqz:
.. _doxid-quaternion_8h_1a5042754735d29732f848be2b81117b0e:
.. _cid-ksl_product_qqzf:
.. _doxid-quaternion_8h_1a9d7a0febeb71a16d2b73ed58a6fdd930:
.. _cid-ksl_quaternion_product_qzconjq:
.. _doxid-quaternion_8h_1a301a801185cd045140bf94e80fdfbc87:
.. _cid-ksl_product_qzconjqf:
.. _doxid-quaternion_8h_1adfd20be00cd7a645bc185e70cabba684:
.. _cid-ksl_quaternion_product_qconjqz:
.. _doxid-quaternion_8h_1ae3edad2dcaf592675a59ce24a8fc906c:
.. _cid-ksl_product_qconjqzf:
.. _doxid-quaternion_8h_1a0d07b5f0e1b8e570d94d1a80f8f72d6c:
.. _cid-ksl_quaternion_product_qzqconj:
.. _doxid-quaternion_8h_1a03904bd63790cfb664b05bf1aec20973:
.. _cid-ksl_product_qzqconjf:
.. _doxid-quaternion_8h_1a4e9d5bc0dd52d56e01455c8181e8a8df:
.. _cid-ksl_quaternion_product_qqzconj:
.. _doxid-quaternion_8h_1a597d83bbce370e77ed0e9eee479e86cd:
.. _cid-ksl_product_qqzconjf:
.. _doxid-quaternion_8h_1a027c9cdd3528233b760e96c9f99e0aa1:
.. _cid-ksl_quaternion_product_qzconjqconj:
.. _doxid-quaternion_8h_1ab7a9ecf681904b26ec0acf7f8f91c1db:
.. _cid-ksl_product_qzconjqconjf:
.. _doxid-quaternion_8h_1a89c939f6401f49ffb00ecfd7e682de9d:
.. _cid-ksl_quaternion_product_qconjqzconj:
.. _doxid-quaternion_8h_1a933c86b3810bd63a3e71bfe3a893b8ef:
.. _cid-ksl_product_qconjqzconjf:
.. _doxid-quaternion_8h_1aae498f7c356b80178b965fc0a8e26545:
.. _cid-ksl_quaternion_product_qv:
.. _doxid-quaternion_8h_1a7f5977e1cd226e1d5eb918abebee51da:
.. _cid-ksl_product_qvf:
.. _doxid-quaternion_8h_1ad528bd7febbbb3359c1bbb12e8672a7e:
.. _cid-ksl_quaternion_product_qconjv:
.. _doxid-quaternion_8h_1a60fa075831c5e7cf210ae780ad17509d:
.. _cid-ksl_product_qconjvf:
.. _doxid-quaternion_8h_1a4d2b87c1dfa7776e9dbc646f1bd0ffd9:
.. _cid-ksl_quaternion_product_vq:
.. _doxid-quaternion_8h_1ab3c149b03615e37966fca83414667a91:
.. _cid-ksl_product_vqf:
.. _doxid-quaternion_8h_1adbfbb4f9f2fc8533c29088294f749818:
.. _cid-ksl_quaternion_product_vqconj:
.. _doxid-quaternion_8h_1aeead61262650d87e9d13bd98c49de293:
.. _cid-ksl_product_vqconjf:
.. _doxid-quaternion_8h_1aed3e1e363794e553d87d924afb01016a:
.. _cid-ksl_quaternion_product_uqinverseq:
.. _doxid-screw_8h_1a63b887e9de33ea03b541fbc9d985b232:
.. _cid-ksl_screw_norm:
.. _doxid-screw_8h_1a320ad3fdc2e199e8638cfaf487ed8de6:
.. _cid-ksl_screwf_norm:
.. _doxid-screw_8h_1a21ea5f22b88817fba0adb63b118c0654:
.. _cid-ksl_dot_cs:
.. _doxid-screw_8h_1a6c4c7aee0386f6847650cf9a83336240:
.. _cid-ksl_dot_csf:
.. _doxid-screw_8h_1ace8288864ae74b66f23d5c80d8e32e36:
.. _cid-ks_screw_scale:
.. _doxid-screw_8h_1a5c6f25b9ffae60a91a462cda40136fa7:
.. _cid-ksl_screw_copy:
.. _doxid-screw_8h_1a9b38f6219c0b2ad9504d5d1a9c7c652f:
.. _cid-ksl_screwf_copy:
.. _doxid-screw_8h_1a3b1aea456f3d39464b038afc44fb97f1:
.. _cid-ksl_screw_invert:
.. _doxid-screw_8h_1a6405e06d36986bdcd43fce3084c24461:
.. _cid-ksl_screwf_invert:
.. _doxid-screw_8h_1aa2765f5d941bc8d85286a06ba74f3669:
.. _cid-ksl_screw_inverted:
.. _doxid-screw_8h_1a0009bdfe7542a64fc2383d193c8c202d:
.. _cid-ksl_screwf_inverted:
.. _doxid-screw_8h_1abcab2c37336344271936eca5eebd07b7:
.. _cid-ksl_axpy_ss:
.. _doxid-screw_8h_1ade69b9088fef0ec2689b3c9ce60472f7:
.. _cid-ksl_axpy_ssf:
.. _doxid-screw_8h_1a030fb18f21d0e205b91e9a43fa72952e:
.. _cid-ksl_xpy_ss:
.. _doxid-screw_8h_1a3c7c48bc899eec2ba4d654316e860f8b:
.. _cid-ksl_xpy_ssf:
.. _doxid-screw_8h_1aed7ec16489a53e348a93db9e61e4302e:
.. _cid-ksl_nxpy_ss:
.. _doxid-screw_8h_1a06f69525c025aff9c5ad730dfd4d1441:
.. _cid-ksl_nxpy_ssf:
.. _doxid-screw_8h_1ab69b2bfaf7392069783026c10d09b426:
.. _cid-ksl_product_sa:
.. _doxid-screw_8h_1a68ecd0c5f7fff5b19de15059df451e1b:
.. _cid-ksl_product_saf:
.. _doxid-screw_8h_1a8eb9d4d35c89e369b2f2fd2a4af5edfb:
.. _cid-ksl_add_ss:
.. _doxid-screw_8h_1a3c9494d3792e49454c7fbb3ac2d89352:
.. _cid-ksl_add_ssf:
.. _doxid-screw_8h_1aa9fa9d761704fa1153f623507352348d:
.. _cid-ksl_subtract_ss:
.. _doxid-screw_8h_1ad86f76d66b897618d6e0bce5a9edde02:
.. _cid-ksl_subtract_ssf:
.. _doxid-screw_8h_1a694609a9973a623afeefda1bc064dae2:
.. _cid-ksl_add_sst:
.. _doxid-screw_8h_1ae4371aea3644d376a82ecf329ce934fb:
.. _cid-ksl_add_sstf:
.. _doxid-screw_8h_1afe2ef0d4a1122930410c642897d98c38:
.. _cid-ksl_htx:
.. _doxid-screw_8h_1a1f13aea633ae9ca05fd505ee42438a9c:
.. _cid-ksl_htxf:
.. _doxid-screw_8h_1a1847fad4a681462988904e25470334fc:
.. _cid-ksl_hty:
.. _doxid-screw_8h_1ab5097bed364627bfafd5d2ffc1a65c21:
.. _cid-ksl_htyf:
.. _doxid-screw_8h_1a6c9fd5d6bda14c8776a9039da9c68edb:
.. _cid-ksl_htz:
.. _doxid-screw_8h_1afb53bc09a2fd5ccacb58a3d3a59e2cda:
.. _cid-ksl_htzf:
.. _doxid-screw_8h_1ab5fbd0fad8e93a98f1739d487548baab:
.. _cid-ksl_hrx:
.. _doxid-screw_8h_1a52cb7ed0ef48209762827917f7628ca2:
.. _cid-ksl_hrxf:
.. _doxid-screw_8h_1a34682efe1a0b82d7922aa422b30fb337:
.. _cid-ksl_hry:
.. _doxid-screw_8h_1a12134a4aa42f6da6b546e1310075236b:
.. _cid-ksl_hrz:
.. _doxid-screw_8h_1a26a98b68c63a0fae907df9a1e8bd8fb8:
.. _cid-ksl_hrzf:
.. _doxid-screw_8h_1a64e6347999ca22e50bcc471cd0c0e35e:
.. _cid-ksl_htxinv:
.. _doxid-screw_8h_1ab0f67034f70fb3b1d32b6bebd0935b7f:
.. _cid-ksl_htxinvf:
.. _doxid-screw_8h_1a518f1c41de8bb4b75fcfeb4835f262c2:
.. _cid-ksl_htyinv:
.. _doxid-screw_8h_1a89fe85bfca60c9b6b08952749fb44d31:
.. _cid-ksl_htyinvf:
.. _doxid-screw_8h_1a913fceabb404e4a65e7a8f397207a760:
.. _cid-ksl_htzinv:
.. _doxid-screw_8h_1a870420bb6b1ccd4c7ff6e343d78c5b28:
.. _cid-ksl_htzinvf:
.. _doxid-screw_8h_1ae03a4efc62eb052700680af0a562b1ec:
.. _cid-ksl_hrxinv:
.. _doxid-screw_8h_1aef7516989eb0ce1827d94389afb34d79:
.. _cid-ksl_hrxinvf:
.. _doxid-screw_8h_1a644b5464130512659a1231f13916e7ed:
.. _cid-ksl_hryinv:
.. _doxid-screw_8h_1aa704f202430c33b994ad397702e73b54:
.. _cid-ksl_hryinvf:
.. _doxid-screw_8h_1ad8858eccb5fa00cbba06989f3d362ead:
.. _cid-ksl_hrzinv:
.. _doxid-screw_8h_1a41cf5ba358ed78f8a40201b7074dc309:
.. _cid-ksl_hrzinvf:
.. _doxid-screw_8h_1a3f90c6d736fcf3adcc7cede0de5ac98d:
.. _cid-ksl_cross_ss:
.. _doxid-screw_8h_1ac66af38b3761c8d4bf0f56fa4c248385:
.. _cid-ksl_cross_ssf:
.. _doxid-screw_8h_1a92a2407b4024712b0fbee78f896ed203:
.. _cid-ksl_cross_sst:
.. _doxid-screw_8h_1ab77558baa443db0a9ac3003b2e5fe8c0:
.. _cid-ksl_cross_sstf:
.. _doxid-screw_8h_1a22606f0ceb8788b12eb25a20d38be7a1:
.. _cid-ksl_product_adrs:
.. _doxid-screw_8h_1ae2aa2e7020f68dd9b4716b9400cc754e:
.. _cid-ksl_product_adrsinv:
.. _doxid-screw_8h_1a3c6d2dedcb47ca15e4dfa198f84a6a44:
.. _cid-ksl_product_adrsf:
.. _doxid-screw_8h_1ac1c548130b277dc68ed9c72bff498030:
.. _cid-ksl_product_adrsinvf:
.. _doxid-screw_8h_1aadc61d866d74258ccc9bdfe151213ff8:
.. _cid-ksl_product_adrinvs:
.. _doxid-screw_8h_1a5f1226ded1159f5695a22f944302f418:
.. _cid-ksl_product_adrinvsf:
.. _doxid-screw_8h_1ad608d5b26172dbcc52dbd454b664e693:
.. _cid-ksl_product_adts:
.. _doxid-screw_8h_1a3d09944886b213613b15da820f5f74ef:
.. _cid-ksl_product_adtsf:
.. _doxid-screw_8h_1aff6e27f1af1f740ab4ff3319a74b3a69:
.. _cid-ksl_product_adtinvs:
.. _doxid-screw_8h_1aa9f5f696af95682f42ffdef47ba0dbc6:
.. _cid-ksl_product_adtinvsf:
.. _doxid-screw_8h_1ac01634179e19f20f6bd8c7cbc597437d:
.. _cid-ksl_product_adtsinv:
.. _doxid-screw_8h_1a3dabab03e28df14d9bd91f67e6d9061f:
.. _cid-ksl_product_adtsinvf:
.. _doxid-screw_8h_1a1d19786f414359ed21a6649d8be99e57:
.. _cid-ksl_product_ads:
.. _doxid-screw_8h_1ac9de2b0dfe4e74cf65f3238c0745a675:
.. _cid-ksl_product_adsinv:
.. _doxid-screw_8h_1a14769fe5e3c6d68015c47bfebecd6b24:
.. _cid-ksl_product_adsf:
.. _doxid-screw_8h_1a66239941994450b928f4ce8fd2016f2c:
.. _cid-ksl_product_adinvs:
.. _doxid-screw_8h_1a15fa0415230d31423d5d363ccaa73d62:
.. _cid-ksl_product_adinvsf:
.. _doxid-util_8h_1a58d35bf9e1057153f40884a9b8af45fa:
.. _cid-ksl_swap:
.. _doxid-util_8h_1a4afe69a3d6be1faec4634dea5973860e:
.. _cid-ksl_swapf:
.. _doxid-util_8h_1ad391c31af317f81e7dda9e696e9e35d4:
.. _cid-ksl_swapi:
.. _doxid-util_8h_1a5145832ca74d91868188352b8075d760:
.. _cid-ksl_axpy:
.. _doxid-util_8h_1af550118ac48ea10796711c96e7c92b62:
.. _cid-ksl_axpyf:
.. _doxid-util_8h_1ad2dc546bbd306c2b5876aab535faff44:
.. _cid-ksl_allclose:
.. _doxid-util_8h_1ae6fe09a23674a2ca8dab5cad28277217:
.. _cid-ksl_allclosef:
.. _doxid-util_8h_1ab083d67beaad577a1f8273910996ca2a:
.. _cid-ksl_arraylerp:
.. _doxid-util_8h_1a64da2905a6a2d7cb1521af05138e0b51:
.. _cid-ksl_arraylerpf:
.. _doxid-vector_8h_1a08e257a47562dc6e060faa7891363e88:
.. _cid-ksl_vec3_l2norm:
.. _doxid-vector_8h_1a19ea31a44f869ce9e065b4a95089532c:
.. _cid-ksl_vec3f_l2norm:
.. _doxid-vector_8h_1a64e470bc534fdc08721184d2aacd9e99:
.. _cid-ksl_vec3_normalize:
.. _doxid-vector_8h_1af64dbf7f6d7490a852007462f1c6d17b:
.. _cid-ksl_vec3f_normalize:
.. _doxid-vector_8h_1a16c3485deb9296193dde72899be9da87:
.. _cid-ksl_vec3_scale:
.. _doxid-vector_8h_1a5d096a62536a90df6d0f49f95e0d0a4c:
.. _cid-ksl_vec3f_scale:
.. _doxid-vector_8h_1ab46dd6f273814deca232cde08fa8bf95:
.. _cid-ksl_vec3_copy:
.. _doxid-vector_8h_1a785b776d82f4f5b05321769235f202e6:
.. _cid-ksl_vec3f_copy:
.. _doxid-vector_8h_1a7adf5528745f85dfc405d90749f7a46d:
.. _cid-ksl_vec3_swap:
.. _doxid-vector_8h_1aa98d35730aae0c882ba47d5e3dc210e1:
.. _cid-ksl_vec3f_swap:
.. _doxid-vector_8h_1a46e649b51c5d0f86a6ed8c6915193d18:
.. _cid-ksl_vec3_inverted:
.. _doxid-vector_8h_1ab1acc06d157dc058819c1271fd83cb1f:
.. _cid-ksl_vec3_invert:
.. _doxid-vector_8h_1a877225ef397c196915afed0dfc482ccc:
.. _cid-ksl_vec3f_inverted:
.. _doxid-vector_8h_1a2654f6d5ae904f75d156eb7c0ef44ca0:
.. _cid-ksl_vec3f_invert:
.. _doxid-vector_8h_1a4deaa1bbadb267a58ed72af232ff0dda:
.. _cid-ksl_dot_vv:
.. _doxid-vector_8h_1a7148bcc549ea99d55ae631d374ca1b1e:
.. _cid-ksl_dot_vvf:
.. _doxid-vector_8h_1ace9bfb003159938d4bf31226763b40b8:
.. _cid-ksl_product_av:
.. _doxid-vector_8h_1a479c86aa552bdc92c253ceaae813acba:
.. _cid-ksl_product_avinv:
.. _doxid-vector_8h_1aa8e241b5d9d5fdd75b6a8d1901b6ca2c:
.. _cid-ksl_product_ainvv:
.. _doxid-vector_8h_1ab69a5984f0b7bc4e7afe0b56d8bd4d19:
.. _cid-ksl_product_avf:
.. _doxid-vector_8h_1a9cf96e265dbd2766a1ae13d4922b2174:
.. _cid-ksl_add_vv:
.. _doxid-vector_8h_1a0fd563dc9f835dcc46b716aec4b4bc8f:
.. _cid-ksl_add_vvf:
.. _doxid-vector_8h_1a0e4744808eef504442177147c9990021:
.. _cid-ksl_subtract_vv:
.. _doxid-vector_8h_1ac2f9de0e3e7a6b46d219c8af57e57eff:
.. _cid-ksl_subtract_vvf:
.. _doxid-vector_8h_1a1635f0edb87f1a372bb97a332e514ac9:
.. _cid-ksl_axpy_vv:
.. _doxid-vector_8h_1a06d2045b92f6070004e413caefd7a601:
.. _cid-ksl_axpy_vvf:
.. _doxid-vector_8h_1a1eefd397920c924eb17d4f0858edd3bd:
.. _cid-ksl_nxpy_vv:
.. _doxid-vector_8h_1a799019ca19f7c4a1bedd94f549265400:
.. _cid-ksl_nxpy_vvf:
.. _doxid-vector_8h_1a307d6f874e2de524a49e2d64f2d29ff4:
.. _cid-ksl_xpy_vv:
.. _doxid-vector_8h_1a8320fd04e1e07b05d211f30dc7592c6a:
.. _cid-ksl_xpy_vvf:
.. _doxid-vector_8h_1a0ce91de57becc29c1111b0bf73936cbf:
.. _cid-ksl_cross_vv:
.. _doxid-vector_8h_1af6bd906c2a20ff004f7c51fa47005cd5:
.. _cid-ksl_cross_vvinv:
.. _doxid-vector_8h_1a11374bbdcea66a3d6382a02cda5684db:
.. _cid-ksl_cross_vvf:
.. _doxid-vector_8h_1a3e8bebd2a16367844239e4f4dd83cb07:
.. _cid-ksl_cross_vvinvf:
.. _doxid-vector_8h_1af2bc368983fb114c245e015c5b982031:
.. _cid-ksl_add_vvx:
.. _doxid-vector_8h_1ad858c3bfd21ad1d7ae3479cdf2170047:
.. _cid-ksl_add_vvxf:
.. _doxid-vector_8h_1ade204344b4621ff03d8ae317fb9084f8:
.. _cid-ksl_add_vvxinv:
.. _doxid-vector_8h_1a56419d2c08f8bb93580318d26c044d60:
.. _cid-ksl_add_vvxinvf:
.. _doxid-vector_8h_1a17222b1b8ab8707aad868260295ff12b:
.. _cid-ksl_add_vvy:
.. _doxid-vector_8h_1a50a0619e91300563d62b93e36f32d417:
.. _cid-ksl_add_vvyf:
.. _doxid-vector_8h_1ac3c5bf7d99d75e16eee609eef2298494:
.. _cid-ksl_add_vvyinv:
.. _doxid-vector_8h_1a09e0bda1823817216e9a0bdc388cbb63:
.. _cid-ksl_add_vvyinvf:
.. _doxid-vector_8h_1a87a0b93e420904eabde3c4244b1e52f2:
.. _cid-ksl_add_vvz:
.. _doxid-vector_8h_1a6e81b8767041e850ca54c2d4b023399f:
.. _cid-ksl_add_vvzf:
.. _doxid-vector_8h_1aa8a9ae01a96269cf5c33de109dc37620:
.. _cid-ksl_add_vvzinv:
.. _doxid-vector_8h_1a37fb54d72325d10828c6ccde9615a0e6:
.. _cid-ksl_add_vvzinvf:
.. ref-code-block:: cpp
	:class: overview-code-block

	// typedefs

	typedef union :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>` :ref:`ksl_coscrew_t<doxid-coscrew_8h_1a5b617cad1ce335f5fa0e1c1b154b218b>`
	typedef union :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>` :ref:`ksl_coscrewf_t<doxid-coscrew_8h_1aedb6901eed09e5dd2f118b364c919989>`
	typedef union :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>` :ref:`ksl_inertia_t<doxid-inertia_8h_1ab5504921d52b35bd14646b1639cabae4>`
	typedef union :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>` :ref:`ksl_inertiaf_t<doxid-inertia_8h_1ac6dbc27a2d0ca2c67e9a2628a29bdd48>`
	typedef union :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` :ref:`ksl_mat3x3_t<doxid-matrix_8h_1a863840d209066dfd1ca372e8cda4a49a>`
	typedef union :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` :ref:`ksl_mat3x3f_t<doxid-matrix_8h_1af4fc311539d1e7c3c1ce4a41f02ec525>`
	typedef union :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>` :ref:`ksl_mat4x4_t<doxid-matrix_8h_1a64ef9c412911c875c18f7d2a041d659f>`
	typedef union :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>` :ref:`ksl_mat4x4f_t<doxid-matrix_8h_1aa56e697b2a1af31d8412d010211d4226>`
	typedef union :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>` :ref:`ksl_SE3_t<doxid-matrix_8h_1ab37691dc0938113b7b869106d2789b8b>`
	typedef union :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>` :ref:`ksl_SE3f_t<doxid-matrix_8h_1a0ee2a29576f0cfebd2ae40be3f617ad8>`
	typedef union :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>` :ref:`ksl_quaternion_t<doxid-quaternion_8h_1a6d3b5afafd28388383e266b39d3a34de>`
	typedef union :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>` :ref:`ksl_quaternionf_t<doxid-quaternion_8h_1a7ed82a089af99d93ddd9aacb042ef39f>`
	typedef union :ref:`ksl_screw_t<doxid-unionksl__screw__t>` :ref:`ksl_screw_t<doxid-screw_8h_1adfdee77c959ed2002f87b6872bafaa87>`
	typedef union :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>` :ref:`ksl_screwf_t<doxid-screw_8h_1a420a434d0aae4bee7dbe344c40f3fc74>`
	typedef union :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` :ref:`ksl_vec3_t<doxid-vector_8h_1aa096ee2edca674d88dc28b0e7ebfde4e>`
	typedef union :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` :ref:`ksl_vec3f_t<doxid-vector_8h_1a020678e38102a360c21581cbc52f746d>`
	typedef union :ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>` :ref:`ksl_vec3i_t<doxid-vector_8h_1a33faca033f8438404795029c6d225502>`
	typedef union :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>` :ref:`ksl_vec4_t<doxid-vector_8h_1ae1be892e03dc2719593a18ec4e1a31ba>`
	typedef union :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>` :ref:`ksl_vec4f_t<doxid-vector_8h_1a81e1854552d43053a66740237a5ac8ca>`

	// enums

	enum :ref:`ksl_axis_enum_t<doxid-axis_8h_1afe15d8a28514e4034eef07dfecf3040b>`

	// unions

	union :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	union :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	union :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`
	union :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`
	union :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`
	union :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`
	union :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`
	union :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`
	union :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	union :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	union :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`
	union :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`
	union :ref:`ksl_screw_t<doxid-unionksl__screw__t>`
	union :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`
	union :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`
	union :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`
	union :ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`
	union :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`
	union :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`

	// global functions

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`
	:ref:`ksl_axis_getVector<doxid-axis_8h_1aeb4cb5d810cf9f519a2fbfbf11214c1e>` (ksl_axis_enum_t axisType)

	ksl_axis_enum_t
	ksl_axis_enumFromChar (const char*)

	:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`*
	:ref:`ksl_coscrew_alloc<doxid-coscrew_8h_1aab33021ec14747fedfd5bf876027a94f>` (int)

	:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`*
	:ref:`ksl_coscrewf_alloc<doxid-coscrew_8h_1a8c0496bb9692d77f5effea9aa2ff62e7>` (int)

	void
	ksl_cross_cc (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* s1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* s2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* so
	    )

	void
	ksl_cross_ccf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* s1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* s2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* so
	    )

	void
	ksl_product_CoAdtc (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* si,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* so
	    )

	void
	ksl_product_CoAdtcf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* si,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* so
	    )

	void
	ksl_product_CoAdtcinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* si,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* so
	    )

	void
	ksl_product_CoAdtcinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* si,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* so
	    )

	void
	ksl_product_CoAdc (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* si,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* so
	    )

	void
	ksl_product_CoAdcf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* si,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* so
	    )

	void
	ksl_product_CoAdinvc (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* si,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	ksl_product_CoAdinvcf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* si,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* so
	    )

	:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`*
	ksl_inertia_alloc (int)

	:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`*
	ksl_inertiaf_alloc (int)

	void
	ksl_inertia_rotated (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

	void
	ksl_inertiaf_rotated (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

	void
	ksl_inertia_rotate (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r
	    )

	void
	ksl_inertiaf_rotate (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r
	    )

	void
	ksl_inertia_translated (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* r,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

	void
	ksl_inertiaf_translated (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* r,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

	void
	ksl_inertia_translate (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* r
	    )

	void
	ksl_inertiaf_translate (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* r
	    )

	void
	ksl_inertia_transformed (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

	void
	ksl_inertiaf_transformed (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

	void
	ksl_inertia_merge (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t_ic_i,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_j,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t_jc_j,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D_ij
	    )

	void
	ksl_inertiaf_merge (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t_ic_i,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_j,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t_jc_j,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D_ij
	    )

	int
	ksl_inertia_factor (:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`*)

	void
	ksl_linalg_gramSchmidt (
	    double* A,
	    int m,
	    int n
	    )

	void
	ksl_linalg_pca (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* A,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* v
	    )

	void
	ksl_swapArray (
	    const int n,
	    double* a,
	    const int a_stride,
	    double* b,
	    const int b_stride
	    )

	int
	ksl_maxIndex (
	    const int n,
	    const double* a
	    )

	void
	ksl_linalg_lu (
	    const int rank,
	    const int colDim,
	    double* A
	    )

	void
	ksl_linalg_lu_backwardSubstitution (
	    const double* L,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_lu_forwardSubstitution (
	    const double* U,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_lu_solve (
	    const int rowDim,
	    const int colDim,
	    const double* A,
	    int* pr,
	    int* pc,
	    const double* x,
	    double* y,
	    const int n
	    )

	int
	ksl_linalg_lu_full (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    const double eps,
	    int* pr,
	    int* pc
	    )

	int
	ksl_linalg_lu_full_specified (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    const double eps,
	    int* pr,
	    int* pc,
	    const int specifiedIndex
	    )

	void
	ksl_linalg_lu_full_backwardSubstitution (
	    const double* L,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_lu_full_forwardSubstitution (
	    const double* U,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_lu_full_solve (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    int* pr,
	    int* pc,
	    double* x,
	    double* y
	    )

	void
	ksl_linalg_lu_setBMatrix (
	    const int rank,
	    const int colDim,
	    double* A
	    )

	void
	:ref:`ksl_linalg_lu_setCMatrix<doxid-linalg_8h_1a0cb848b241f3fa36ebfcc959fae05008>` (
	    const int rowDim,
	    const int colDim,
	    int rank,
	    double* A
	    )

	int
	ksl_linalg_ldlt (
	    double* D,
	    const int n
	    )

	void
	ksl_linalg_ldlt_backwardSubstitution (
	    const double* L,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_ldlt_forwardSubstitution (
	    const double* L,
	    const double* b,
	    double* y,
	    const int n
	    )

	void
	ksl_linalg_ldlt_solve (
	    const double* A,
	    const double* x,
	    double* y,
	    const int n
	    )

	int
	ksl_linalg_cholesky (
	    double* D,
	    const int n
	    )

	void
	ksl_linalg_cholesky_forwardSubstitution (
	    const double* L,
	    const double* b,
	    double* y,
	    const int n
	    )

	void
	ksl_linalg_cholesky_backwardSubstitution (
	    const double* L,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_cholesky_solve (
	    const double* A,
	    const double* x,
	    double* y,
	    const int n
	    )

	int
	ksl_linalg_symmetricMatrixInverse (
	    double* A,
	    const int n
	    )

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`*
	ksl_SE3_alloc (int)

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`*
	ksl_SE3f_alloc (int)

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*
	ksl_mat3x3_alloc (int)

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*
	ksl_mat3x3f_alloc (int)

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`*
	ksl_mat4x4_alloc (int)

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`*
	ksl_mat4x4f_alloc (int)

	void
	ksl_SE3_toMat4x4 (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* m
	    )

	void
	ksl_SE3f_toMat4x4f (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d,
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* m
	    )

	void
	ksl_SE3_toMat4x4f (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* m
	    )

	void
	ksl_dc (
	    double thetai,
	    double dc [2]
	    )

	void
	ksl_SE3_setIdentity (:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d)

	void
	ksl_SE3f_setIdentity (:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d)

	void
	ksl_mat3x3_setIdentity (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r)

	void
	ksl_mat3x3f_setIdentity (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r)

	void
	ksl_mat3x3_set (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const int row,
	    const int column,
	    const double value
	    )

	void
	ksl_mat4x4_set (
	    :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* R,
	    const int row,
	    const int column,
	    const double value
	    )

	void
	ksl_SE3_set (
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    const int row,
	    const int column,
	    const double value
	    )

	void
	ksl_SE3f_set (
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    const int row,
	    const int column,
	    const float value
	    )

	void
	ksl_mat3x3_setFromVectors (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* x,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* y,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* z
	    )

	void
	ksl_mat3x3f_set (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    int row,
	    int column,
	    float value
	    )

	void
	ksl_mat4x4f_set (
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* D,
	    int row,
	    int column,
	    float value
	    )

	void
	ksl_mat4x4_setIdentity (:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* M)

	void
	ksl_mat4x4f_setIdentity (:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* M)

	double
	ksl_SE3_get (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    const int row,
	    const int column
	    )

	double
	ksl_mat3x3_get (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const int row,
	    const int column
	    )

	float
	ksl_mat3x3f_get (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    const int row,
	    const int column
	    )

	float
	ksl_SE3f_get (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    const int row,
	    const int column
	    )

	void
	ksl_SE3_getTranslation (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t
	    )

	void
	ksl_mat3x3_copy (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_mat3x3f_copy (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_mat3x3_invert (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R)

	void
	ksl_mat3x3_inverted (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_mat3x3_transpose (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R)

	void
	ksl_mat3x3f_transpose (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R)

	void
	ksl_mat3x3_transposed (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_mat3x3f_transposed (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_SE3_invert (:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D)

	void
	ksl_SE3f_invert (:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D)

	void
	ksl_SE3_inverted (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_SE3f_inverted (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_SE3_copy (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_SE3f_copy (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_mat3x3_getEulerAngles (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* rin,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* angles,
	    const ksl_axis_enum_t axisType
	    )

	void
	ksl_mat3x3_setFromEulerAngles (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*,
	    const ksl_axis_enum_t axisType
	    )

	double
	ksl_mat3x3_getScalar (const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri)

	float
	ksl_mat3x3f_getScalar (const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri)

	void
	ksl_mat3x3_getAxisAngle (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*,
	    double*
	    )

	void
	ksl_mat4x4_getTranslation (
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* Mi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_mat4x4f_getTranslation (
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* Mi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	double
	ksl_mat4x4_get (
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* Mi,
	    const int row,
	    const int column
	    )

	float
	ksl_mat4x4f_get (
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* Mi,
	    const int row,
	    const int column
	    )

	double
	ksl_mat3x3_determinant (const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*)

	void
	ksl_product_drv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drinvv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drinvvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drinvvinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drinvvinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvtx (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvtxf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvtxinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvtxinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvty (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvtyf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvtyinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvtyinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvtz (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvtzf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drvtzinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_drvtzinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_product_drdrx (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdrxf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdrxinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdrxinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdry (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdryf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdryinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdryinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdrz (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdrzf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdrzinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdrzinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdr (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdrf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drdrinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drdrinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_drinvdr (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_product_drinvdrf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_product_dv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_dinvv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_ddrx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddrxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddrxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddrxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddry (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddryf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddryinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddryinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddrz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddrzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddrzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddrzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddt (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_dinvdt (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_dinvdtf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddtx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddty (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtyf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddtyinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtyinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddtz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddtzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddtzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddr (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddrf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddrinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddrinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_dd (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D1i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D2i,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D1i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D2i,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_product_ddinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D1i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D2i,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	ksl_product_ddinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D1i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D2i,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	ksl_vec3_print (
	    FILE* f,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi
	    )

	void
	ksl_vec3f_print (
	    FILE* f,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi
	    )

	void
	ksl_quaternion_print (
	    FILE* f,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi
	    )

	void
	ksl_quaternionf_print (
	    FILE* f,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi
	    )

	void
	ksl_screw_print (
	    FILE* f,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si
	    )

	void
	ksl_screwf_print (
	    FILE* f,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si
	    )

	void
	ksl_mat3x3_print (
	    FILE* f,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r
	    )

	void
	ksl_mat3x3f_print (
	    FILE* f,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r
	    )

	void
	ksl_SE3_print (
	    FILE* f,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d
	    )

	void
	ksl_mat4x4_print (
	    FILE* f,
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* d
	    )

	void
	ksl_mat4x4f_print (
	    FILE* f,
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* d
	    )

	void
	ksl_array_print (
	    FILE* f,
	    const int n,
	    const double* a
	    )

	void
	ksl_array_print2D (
	    FILE* f,
	    const int rowDim,
	    const int colDim,
	    const bool isRowMajor,
	    const double* a
	    )

	void
	ksl_arrayi_print (
	    FILE* f,
	    const int n,
	    const int* a
	    )

	void
	ksl_triang_print (
	    FILE* f,
	    const int n,
	    const double* a
	    )

	void
	ksl_triangi_print (
	    FILE* f,
	    const int n,
	    const int* a
	    )

	void
	ksl_triangb_print (
	    FILE* f,
	    const int n,
	    const bool* a
	    )

	void
	ksl_inertia_print (
	    FILE* f,
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia
	    )

	:ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`*
	:ref:`ksl_quaternion_alloc<doxid-quaternion_8h_1ab935a7bb4ec6abcaebbce78c42c363d1>` (int)

	:ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`*
	:ref:`ksl_quaternionf_alloc<doxid-quaternion_8h_1a3c55240b57e480b0052f755e37b17e9e>` (int)

	double
	ksl_quaternion_dot_qq (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`*,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`*
	    )

	float
	ksl_dot_qqf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`*,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`*
	    )

	void
	ksl_quaternion_normalize (:ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi)

	void
	ksl_quaternionf_normalize (:ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi)

	void
	ksl_axpy_qq (
	    double,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`*,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`*
	    )

	void
	ksl_axpy_qqf (
	    float,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`*,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`*
	    )

	void
	ksl_mat3x3_toQuaternion (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_mat3x3f_toQuaternion (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_toMat3x3 (
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	ksl_quaternionf_toMat3x3f (
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	ksl_quaternion_slerp (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    double* t,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_slerpf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q1i,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q2i,
	    float* t,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_squad (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>` qi [4],
	    double* t,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_squadf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>` qi [4],
	    float* t,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_nlerp (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    const double* t,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_nlerpf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q1i,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q2i,
	    const float* t,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_add_dpiToq (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* dpi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi
	    )

	void
	ksl_subtract_dpiFromq (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* dpi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi
	    )

	void
	ksl_omega_to_dquaternion (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* w,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* dqo
	    )

	void
	ksl_quaternion_product_qq (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q1i,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q2i,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjq (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q1i,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q2i,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q1i,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q2i,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q1i,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q2i,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qxq (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qxqf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqx (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqxf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qxconjq (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qxconjqf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqx (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqxf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qxqconj (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qxqconjf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqxconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqxconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qxconjqconj (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qxconjqconjf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqxconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqxconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qyq (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qyqf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqy (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqyf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qyconjq (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qyconjqf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqy (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqyf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qyqconj (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qyqconjf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqyconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqyconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qyconjqconj (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qyconjqconjf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqyconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqyconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qzq (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qzqf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqz (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqzf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qzconjq (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qzconjqf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqz (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqzf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qzqconj (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qzqconjf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qqzconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qqzconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qzconjqconj (
	    const double dci [2],
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qzconjqconjf (
	    const float dci [2],
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjqzconj (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const double dci [2],
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjqzconjf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const float dci [2],
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qv (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qvf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_qconjv (
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_qconjvf (
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_vq (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_vqf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_vqconj (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qi,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	void
	ksl_product_vqconjf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qi,
	    :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* qo
	    )

	void
	ksl_quaternion_product_uqinverseq (
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q1i,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q2i,
	    :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* qo
	    )

	:ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	:ref:`ksl_screw_alloc<doxid-screw_8h_1aad20eac64a5f92435c7a7a6fc3081a47>` (int)

	:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	:ref:`ksl_screwf_alloc<doxid-screw_8h_1a48e0f01756ce30aee310448d9ae13975>` (int)

	double
	ksl_screw_norm (const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* v)

	float
	ksl_screwf_norm (const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* v)

	double
	ksl_dot_cs (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`*,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	float
	ksl_dot_csf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`*,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	ks_screw_scale (
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`,
	    const double
	    )

	void
	ksl_screw_copy (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_screwf_copy (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_screw_invert (:ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si)

	void
	ksl_screwf_invert (:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si)

	void
	ksl_screw_inverted (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_screwf_inverted (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_axpy_ss (
	    const double,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	void
	ksl_axpy_ssf (
	    const float,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	ksl_xpy_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	void
	ksl_xpy_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	ksl_nxpy_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	void
	ksl_nxpy_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	ksl_product_sa (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    const double ki,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_saf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    const float ki,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_add_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_add_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_subtract_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_subtract_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_add_sst (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si1,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si2,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_add_sstf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si1,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si2,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_htx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_htxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_hty (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_htyf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_htz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* ri,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_htzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* ri,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_hrx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_hrxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_hry (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_hrz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_hrzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_htxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_htxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_htyinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_htyinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_htzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_htzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_hrxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_hrxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_hryinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_hryinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_hrzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	ksl_hrzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	ksl_cross_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_cross_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_cross_sst (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_cross_sstf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adrs (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adrsinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adrsf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adrsinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adrinvs (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adrinvsf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adts (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adtsf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adtinvs (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adtinvsf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adtsinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adtsinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Ads (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adsinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adsf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_product_Adinvs (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	ksl_product_Adinvsf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	ksl_swap (
	    double* a,
	    double* b
	    )

	void
	ksl_swapf (
	    float* a,
	    float* b
	    )

	void
	ksl_swapi (
	    int* a,
	    int* b
	    )

	double
	:ref:`ksl_normalizeDegrees<doxid-util_8h_1ac424ddc2c9a11a36c88bd88613887de4>` (double angle)

	float
	:ref:`ksl_normalizeDegreesf<doxid-util_8h_1a182cf5e0b21887c9cf86a0e4a4c88d53>` (float angle)

	double
	:ref:`ksl_normalizeRadians<doxid-util_8h_1a3bb447a7ec93255beec900be28ca66fc>` (double angle)

	float
	:ref:`ksl_normalizeRadiansf<doxid-util_8h_1aeb321b38b6dbcbed4c676fbdac7aaf1f>` (float angle)

	double
	:ref:`catan2pi<doxid-util_8h_1a81c283138c507d0478a66027bfe85487>` (
	    const double y,
	    const double x,
	    double theta
	    )

	float
	:ref:`catan2pif<doxid-util_8h_1a87fda5b4459e4e6880ab27a53083abf5>` (
	    const float y,
	    const float x,
	    float theta
	    )

	double
	:ref:`catan1pi<doxid-util_8h_1a02f23474b8c71ff5909a3edc4fc03287>` (
	    const double y,
	    const double x,
	    double theta
	    )

	float
	:ref:`catan1pif<doxid-util_8h_1a084e866feca97fa9bd29db3721b11710>` (
	    const float y,
	    const float x,
	    float theta
	    )

	void
	ksl_axpy (
	    const int,
	    const double,
	    const double*,
	    double*
	    )

	void
	ksl_axpyf (
	    const int,
	    const float,
	    const float*,
	    float*
	    )

	bool
	ksl_allclose (
	    const int count,
	    const double* a1,
	    const double* a2
	    )

	bool
	ksl_allclosef (
	    const int count,
	    const float* a1,
	    const float* a2
	    )

	void
	ksl_arraylerp (
	    const int count,
	    const double p,
	    const double* y1i,
	    const double* y2i,
	    double* yo
	    )

	void
	ksl_arraylerpf (
	    const int count,
	    const float p,
	    const float* y1i,
	    const float* y2i,
	    float* yo
	    )

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*
	:ref:`ksl_vec3_alloc<doxid-vector_8h_1a8ff66788e56f867bc2b1c592e698d12f>` (int)

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*
	:ref:`ksl_vec3f_alloc<doxid-vector_8h_1aa2c429697e1dcde474785e471b76b0f5>` (int)

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`*
	:ref:`ksl_vec3i_alloc<doxid-vector_8h_1ac65f639fbad229acffaca7139afadb48>` (int)

	double
	ksl_vec3_l2norm (const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v)

	float
	ksl_vec3f_l2norm (const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v)

	void
	ksl_vec3_normalize (:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v)

	void
	ksl_vec3f_normalize (:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v)

	void
	ksl_vec3_scale (
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v,
	    const double
	    )

	void
	ksl_vec3f_scale (
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v,
	    const float
	    )

	void
	ksl_vec3_copy (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_vec3f_copy (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_vec3_swap (
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_vec3f_swap (
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_vec3_inverted (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_vec3_invert (:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi)

	void
	ksl_vec3f_inverted (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_vec3f_invert (:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi)

	double
	ksl_dot_vv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi0,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi1
	    )

	float
	ksl_dot_vvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi0,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi1
	    )

	void
	ksl_product_av (
	    const double ki,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_avinv (
	    const double ki,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_ainvv (
	    const double ki,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_product_avf (
	    const float ki,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_add_vv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_add_vvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_subtract_vv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_subtract_vvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_axpy_vv (
	    const double scalar,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1x,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2y
	    )

	void
	ksl_axpy_vvf (
	    const float scalar,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1x,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2y
	    )

	void
	ksl_nxpy_vv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1x,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2y
	    )

	void
	ksl_nxpy_vvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1x,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2y
	    )

	void
	ksl_xpy_vv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1x,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2y
	    )

	void
	ksl_xpy_vvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1x,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2y
	    )

	void
	ksl_cross_vv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_cross_vvinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_cross_vvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_cross_vvinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_add_vvx (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t1i,
	    const double t2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_add_vvxf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t1i,
	    const float t2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	void
	ksl_add_vvxinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t1i,
	    const double t2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_add_vvxinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t1i,
	    const float t2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	void
	ksl_add_vvy (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t1i,
	    const double t2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_add_vvyf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t1i,
	    const float t2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	void
	ksl_add_vvyinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t1i,
	    const double t2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_add_vvyinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t1i,
	    const float t2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	void
	ksl_add_vvz (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t1i,
	    const double t2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_add_vvzf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t1i,
	    const float t2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	void
	ksl_add_vvzinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t1i,
	    const double t2i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	ksl_add_vvzinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t1i,
	    const float t2i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	// macros

	#define :ref:`_KSL_H_<doxid-ksl_8h_1a90bb91d1c207348b1765693fedacdf85>`

.. _details-doxid-global:

Detailed Documentation
~~~~~~~~~~~~~~~~~~~~~~



Typedefs
--------

.. _doxid-coscrew_8h_1a5b617cad1ce335f5fa0e1c1b154b218b:
.. _cid-ksl_coscrew_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>` ksl_coscrew_t

double precision coscrew (i.e. a linear operator on a screw), consisting of a linear and angular vector pair in function space.

.. _doxid-coscrew_8h_1aedb6901eed09e5dd2f118b364c919989:
.. _cid-ksl_coscrewf_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>` ksl_coscrewf_t

single precision coscrew (i.e. a linear operator on a screw), consisting of a linear and angular vector pair in function space.

.. _doxid-inertia_8h_1ab5504921d52b35bd14646b1639cabae4:
.. _cid-ksl_inertia_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>` ksl_inertia_t

double precision mass and inertia properties

.. _doxid-inertia_8h_1ac6dbc27a2d0ca2c67e9a2628a29bdd48:
.. _cid-ksl_inertiaf_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>` ksl_inertiaf_t

single precision mass and inertia properties

.. _doxid-matrix_8h_1a863840d209066dfd1ca372e8cda4a49a:
.. _cid-ksl_mat3x3_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` ksl_mat3x3_t

general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by using at / as_array operators. if using the at or as_array operators, then quantities are accessed in column major order

.. _doxid-matrix_8h_1af4fc311539d1e7c3c1ce4a41f02ec525:
.. _cid-ksl_mat3x3f_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` ksl_mat3x3f_t

general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by using at / as_array operators. if using the at or as_array operators, then quantities are accessed in column major order

.. _doxid-matrix_8h_1a64ef9c412911c875c18f7d2a041d659f:
.. _cid-ksl_mat4x4_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>` ksl_mat4x4_t

general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or using at / as_array operators. if using the at / as_array operators, quantities are accessed in column major order

.. _doxid-matrix_8h_1aa56e697b2a1af31d8412d010211d4226:
.. _cid-ksl_mat4x4f_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>` ksl_mat4x4f_t

general 4x4 double precision matrix

allow accessing mat4x4 quantities by field name or using at / as_array operators. if using the at / as_array operators, quantities are accessed in column major order

.. _doxid-matrix_8h_1ab37691dc0938113b7b869106d2789b8b:
.. _cid-ksl_se3_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>` ksl_SE3_t

SE3 (3 Dimensional Special Euclidian group) consists of a SO3 (othonormalized 3x3 rotation matrix) and translation vector pair.

if using the at/as_array operators, quantities are accessed in column major order with Rotation matrix quantities coming first, followed by translation vector

.. _doxid-matrix_8h_1a0ee2a29576f0cfebd2ae40be3f617ad8:
.. _cid-ksl_se3f_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>` ksl_SE3f_t

Single precision member of 3 Dimensional Special Euclidian group (SE3) consisting of a single precision SO3 (othonormalized 3x3 rotation matrix) and single precision translation vector pair.

if using the at/as_array operators, quantities are accessed in column major order with Rotation matrix quantities coming first, followed by translation vector

.. _doxid-quaternion_8h_1a6d3b5afafd28388383e266b39d3a34de:
.. _cid-ksl_quaternion_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>` ksl_quaternion_t

double precision quaternion data structure

.. _doxid-quaternion_8h_1a7ed82a089af99d93ddd9aacb042ef39f:
.. _cid-ksl_quaternionf_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>` ksl_quaternionf_t

single precision quaternion data structure

.. _doxid-screw_8h_1adfdee77c959ed2002f87b6872bafaa87:
.. _cid-ksl_screw_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_screw_t<doxid-unionksl__screw__t>` ksl_screw_t

double precision screw consisting of a linear and angular vector pair in configuration space

.. _doxid-screw_8h_1a420a434d0aae4bee7dbe344c40f3fc74:
.. _cid-ksl_screwf_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>` ksl_screwf_t

single precision screw consisting of a linear and angular vector pair in configuration space

.. _doxid-vector_8h_1aa096ee2edca674d88dc28b0e7ebfde4e:
.. _cid-ksl_vec3_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` ksl_vec3_t

3 dimensional double precision vector

.. _doxid-vector_8h_1a020678e38102a360c21581cbc52f746d:
.. _cid-ksl_vec3f_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` ksl_vec3f_t

3 dimensional single precision vector

.. _doxid-vector_8h_1a33faca033f8438404795029c6d225502:
.. _cid-ksl_vec3i_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>` ksl_vec3i_t

3 dimensional integer vector

.. _doxid-vector_8h_1ae1be892e03dc2719593a18ec4e1a31ba:
.. _cid-ksl_vec4_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>` ksl_vec4_t

double precision 4x1 vector representing a 3x1 vector with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.

.. _doxid-vector_8h_1a81e1854552d43053a66740237a5ac8ca:
.. _cid-ksl_vec4f_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>` ksl_vec4f_t

single precision 4x1 vector representing a 3x1 vector with a homogeneous coordinate (w) appended.

Typically used for nonlinear transformations such as camera projections.

Global Functions
----------------

.. _doxid-axis_8h_1aeb4cb5d810cf9f519a2fbfbf11214c1e:
.. _cid-ksl_axis_getvector:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`
	ksl_axis_getVector (ksl_axis_enum_t axisType)

convert ksl_axis_enum_t to a vector of ints

.. _doxid-coscrew_8h_1aab33021ec14747fedfd5bf876027a94f:
.. _cid-ksl_coscrew_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`*
	ksl_coscrew_alloc (int)

allocate n double precision coscrew quantities

.. _doxid-coscrew_8h_1a8c0496bb9692d77f5effea9aa2ff62e7:
.. _cid-ksl_coscrewf_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`*
	ksl_coscrewf_alloc (int)

allocate n single precision coscrew quantities

.. _doxid-linalg_8h_1a0cb848b241f3fa36ebfcc959fae05008:
.. _cid-ksl_linalg_lu_setcmatrix:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_linalg_lu_setCMatrix (
	    const int rowDim,
	    const int colDim,
	    int rank,
	    double* A
	    )

compute C matrix

This block overwrites LR with LR\*inverse(Lr) Here rank>0 means true rank is greater than 1. If rank==0, the Lr matrix is a 1 by 1 identity matrix, so there is nothing to do here. This loop computes A[rank+1:rowDim-1][0:rank]=LR\*inverse(Lr) where LR is stored in A[rank+1:rowDim-1][0:rank] and Lr is stored in A[0:rank][0:rank]. j is the column number in LR. It ends at 1 because the diagonal entry in row 0 of Lr is 1. i is the row number in LR. k is the column number in Lr

.. _doxid-quaternion_8h_1ab935a7bb4ec6abcaebbce78c42c363d1:
.. _cid-ksl_quaternion_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`*
	ksl_quaternion_alloc (int)

allocate memory for n quaternions and set to identity

.. _doxid-quaternion_8h_1a3c55240b57e480b0052f755e37b17e9e:
.. _cid-ksl_quaternionf_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`*
	ksl_quaternionf_alloc (int)

allocate memory for n quaternions and set to identity

.. _doxid-screw_8h_1aad20eac64a5f92435c7a7a6fc3081a47:
.. _cid-ksl_screw_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	ksl_screw_alloc (int)

allocate n double precision screw quantities

.. _doxid-screw_8h_1a48e0f01756ce30aee310448d9ae13975:
.. _cid-ksl_screwf_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	ksl_screwf_alloc (int)

allocate n single precision screw quantities

.. _doxid-util_8h_1ac424ddc2c9a11a36c88bd88613887de4:
.. _cid-ksl_normalizedegrees:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_normalizeDegrees (double angle)

Normalize double precision angle in degrees.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - normalizes

        - degrees to be between 0 and 360 degrees

.. _doxid-util_8h_1a182cf5e0b21887c9cf86a0e4a4c88d53:
.. _cid-ksl_normalizedegreesf:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_normalizeDegreesf (float angle)

Normalize single precision angle in degrees.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - normalizes

        - degrees to be between 0 and 360 degrees

.. _doxid-util_8h_1a3bb447a7ec93255beec900be28ca66fc:
.. _cid-ksl_normalizeradians:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_normalizeRadians (double angle)

Normalize angle in radians.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - normalizes

        - double precision radians to be between 0 and 2 \* PI radians

.. _doxid-util_8h_1aeb321b38b6dbcbed4c676fbdac7aaf1f:
.. _cid-ksl_normalizeradiansf:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_normalizeRadiansf (float angle)

Normalize angle in radians.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - normalizes

        - single precision radians to be between 0 and 2 \* PI radians

.. _doxid-util_8h_1a81c283138c507d0478a66027bfe85487:
.. _cid-catan2pi:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	catan2pi (
	    const double y,
	    const double x,
	    double theta
	    )

returns a continuous double precision angle obtained from atan2(y, x)

Caution: atan2(y,x) will return an angle with +-2m\*pi accuracy only if the sign on x and y are both correct. If x and y are both off by (-1) then atan2 will return an angle with accuracy of only +-m\*pi. If the sign of x and y are uncertain, use the alternate function, catan1pi.

This function returns a continuous angle obtained from the standard math atan2(y,x) function. On input, the argument theta contains the previous value associated with the angle that is being computed. catan2() adjusts the value returned from atan2(), so it will be as close to theta as possible. The assumption is that the current value to be returned by catan2() is not more than (+-)pi/4 from the previous value. This should be a valid assumption, because angles generally don't change very fast over the course of a simulation. Both input arguments x and y must have the correct sign for catan2pi to work correctly.

.. _doxid-util_8h_1a87fda5b4459e4e6880ab27a53083abf5:
.. _cid-catan2pif:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	catan2pif (
	    const float y,
	    const float x,
	    float theta
	    )

returns a continuous single precision angle obtained from atan2(y, x)

Caution: atan2(y,x) will return an angle with +-2m\*pi accuracy only if the sign on x and y are both correct. If x and y are both off by (-1) then atan2 will return an angle with accuracy of only +-m\*pi. If the sign of x and y are uncertain, use the alternate function, catan1pi.

This function returns a continuous angle obtained from the standard math atan2(y,x) function. On input, the argument theta contains the previous value associated with the angle that is being computed. catan2() adjusts the value returned from atan2(), so it will be as close to theta as possible. The assumption is that the current value to be returned by catan2() is not more than (+-)pi/4 from the previous value. This should be a valid assumption, because angles generally don't change very fast over the course of a simulation. Both input arguments x and y must have the correct sign for catan2pi to work correctly.

.. _doxid-util_8h_1a02f23474b8c71ff5909a3edc4fc03287:
.. _cid-catan1pi:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	catan1pi (
	    const double y,
	    const double x,
	    double theta
	    )

returns a continuous double precision angle from the atan2(y, x) function

Caution: atan2(y,x) will return an angle with +-2m\*pi accuracy only if the sign on x and y are both correct. If x and y are both off by (-1) then atan2 will return an angle with accuracy of only +-m\*pi. If the sign of x and y are certain, this or the alternate function, catan2pi will work. If the sign of x and y are uncertain, do not use catan2pi. This function returns a continuous angle from the standard math atan2(y,x) function. On input, the argument theta contains the previous value associated with the angle that is being computed. catan2() adjusts the value returned from atan2(), so it will be as close to theta as possible. The assumption is that the current value to be returned by catan2() is not more than (+-)pi/4 from the previous value. This should be a valid assumption, because angles generally don't change very fast over the course of a simulation. Both input arguments x and y must either have the correct sign or be off by the same sign for catan1pia() to work correctly.

.. _doxid-util_8h_1a084e866feca97fa9bd29db3721b11710:
.. _cid-catan1pif:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	catan1pif (
	    const float y,
	    const float x,
	    float theta
	    )

returns a continuous single precision angle from the atan2(y, x) function

Caution: atan2(y,x) will return an angle with +-2m\*pi accuracy only if the sign on x and y are both correct. If x and y are both off by (-1) then atan2 will return an angle with accuracy of only +-m\*pi. If the sign of x and y are certain, this or the alternate function, catan2pi will work. If the sign of x and y are uncertain, do not use catan2pi. This function returns a continuous angle from the standard math atan2(y,x) function. On input, the argument theta contains the previous value associated with the angle that is being computed. catan2() adjusts the value returned from atan2(), so it will be as close to theta as possible. The assumption is that the current value to be returned by catan2() is not more than (+-)pi/4 from the previous value. This should be a valid assumption, because angles generally don't change very fast over the course of a simulation. Both input arguments x and y must either have the correct sign or be off by the same sign for catan1pia() to work correctly.

.. _doxid-vector_8h_1a8ff66788e56f867bc2b1c592e698d12f:
.. _cid-ksl_vec3_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*
	ksl_vec3_alloc (int)

initialize n :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` double precision vectors datastructures on the heap

.. _doxid-vector_8h_1aa2c429697e1dcde474785e471b76b0f5:
.. _cid-ksl_vec3f_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*
	ksl_vec3f_alloc (int)

initialize n :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` single precision vectors datastructures on the heap

.. _doxid-vector_8h_1ac65f639fbad229acffaca7139afadb48:
.. _cid-ksl_vec3i_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`*
	ksl_vec3i_alloc (int)

initialize n :ref:`ksl_vec3i_t <doxid-unionksl__vec3i__t>` vectors of integers on the heap

Macros
------

.. _doxid-ksl_8h_1a90bb91d1c207348b1765693fedacdf85:
.. _cid-_ksl_h_:
.. ref-code-block:: cpp
	:class: title-code-block

	#define _KSL_H_

KSL: Kinematics Subroutine Library Kristopher Wehage, Roger Wehage

Kristopher Wehage, Roger Wehage

