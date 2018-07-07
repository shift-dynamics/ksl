.. _global-namespace:

Global Namespace
================

.. index:: pair: namespace; global

.. toctree::
	:hidden:

	enum_ksl_axis_enum_t.rst
	enum_ksl_matrix_enum_t.rst
	enum_ksl_print_breakBetweenLines_enum_t.rst
	struct_ksl_print_options_t.rst
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
	union_ksl_vec4i_t.rst



Overview
~~~~~~~~



.. _doxid-axis_8h_1ad6073885fe924b7021988bab4a48d7aa:
.. _cid-ksl_axis_enumfromchar:
.. _doxid-linalg_8h_1a39fe7ed1c9c5d79e9b853a5c896b5f81:
.. _cid-ksl_linalg_gramschmidt:
.. _doxid-linalg_8h_1a847ae66e3fdbb96c2dfd1907d7e9321b:
.. _cid-ksl_linalg_pca:
.. _doxid-linalg_8h_1a489b07a456ecff304b9248378bdb2246:
.. _cid-ksl_swaparray:
.. _doxid-linalg_8h_1ada2b2790c0d9e02ecfa08a1761ef34bc:
.. _cid-ksl_maxindex:
.. _doxid-linalg_8h_1a782c865f66f96a227edb563474411150:
.. _cid-ksl_linalg_lu_full_rmo:
.. _doxid-linalg_8h_1a9573c1375ddfafde1c66cf75a537c12f:
.. _cid-ksl_linalg_lu_full_specified_rmo:
.. _doxid-linalg_8h_1a72c009e4c082dcbc482b8bf467890617:
.. _cid-ksl_linalg_lu_rmo:
.. _doxid-linalg_8h_1a96a8ac1c53c36d94d0e7c34dc3159d03:
.. _cid-ksl_linalg_lu_setbmatrix_rmo:
.. _doxid-linalg_8h_1a733e638b94ae5d40cf5073bc18213c37:
.. _cid-ksl_linalg_ldlt_rmo:
.. _doxid-linalg_8h_1af58d6198da0ec52ec6208c6e0f430869:
.. _cid-ksl_linalg_cholesky_rmo:
.. _doxid-linalg_8h_1a8b46af65a5770abdb4adcabecb9d297e:
.. _cid-ksl_linalg_ldlt_forwardelimination_rmo:
.. _doxid-linalg_8h_1a1fb51ec8ae3a69704d64d67086ccf5a5:
.. _cid-ksl_linalg_ldlt_backwardsubstitution_rmo:
.. _doxid-linalg_8h_1a2ec7ddcd8441f83f08b8a1e203228975:
.. _cid-ksl_linalg_cholesky_forwardelimination_rmo:
.. _doxid-linalg_8h_1a4c702b8b83bb1e4e5b28b4cf902288f1:
.. _cid-ksl_linalg_cholesky_backwardsubstitution_rmo:
.. _doxid-linalg_8h_1a4dd4bc8a76d30ea900141c4b76255c0e:
.. _cid-ksl_linalg_ldlt_solve_rmo:
.. _doxid-linalg_8h_1a2b69ce5c497f9eed151f91a0838c825c:
.. _cid-ksl_linalg_cholesky_solve_rmo:
.. _doxid-linalg_8h_1ae0e6303411df831afa3b08803537942a:
.. _cid-ksl_linalg_symmetricmatrixinverse_rmo:
.. _doxid-linalg_8h_1aef5c76dd1f149e9bef5186df5c3f000c:
.. _cid-ksl_linalg_lu_full_cmo:
.. _doxid-linalg_8h_1a97c74881b56a37959530054c9b3f7410:
.. _cid-ksl_linalg_lu_full_specified_cmo:
.. _doxid-linalg_8h_1a1c57a37df53ff98cb6ad214485bfe2c3:
.. _cid-ksl_linalg_lu_cmo:
.. _doxid-linalg_8h_1a4ee7a1ffb15e8ca94c9a2170857b6829:
.. _cid-ksl_linalg_lu_setbmatrix_cmo:
.. _doxid-linalg_8h_1a041930fafabd630e9fe3d9ad4d5d9cd8:
.. _cid-ksl_linalg_ldlt_cmo:
.. _doxid-linalg_8h_1a753ac68d8f2711d8313a890066d5912c:
.. _cid-ksl_linalg_cholesky_cmo:
.. _doxid-linalg_8h_1afe3cc744454389b72f711bfdbf97d880:
.. _cid-ksl_linalg_ldlt_forwardelimination_cmo:
.. _doxid-linalg_8h_1a8a3a58247bf30ddb0af1ccc467c85f43:
.. _cid-ksl_linalg_ldlt_backwardsubstitution_cmo:
.. _doxid-linalg_8h_1aa7ce0e99e28cb5ecbb017feb679955e1:
.. _cid-ksl_linalg_cholesky_forwardelimination_cmo:
.. _doxid-linalg_8h_1a5d7875f6d81c9bdca7be5bb1585fee9f:
.. _cid-ksl_linalg_cholesky_backwardsubstitution_cmo:
.. _doxid-linalg_8h_1aa58ede4e08006fb47b9f493c05d4b63c:
.. _cid-ksl_linalg_ldlt_solve_cmo:
.. _doxid-linalg_8h_1ad0a664fb5b6fbd16335b9e67c3dec320:
.. _cid-ksl_linalg_cholesky_solve_cmo:
.. _doxid-linalg_8h_1af981d8f60914ea55286f18ffb9944d1b:
.. _cid-ksl_linalg_symmetricmatrixinverse_cmo:
.. _doxid-print_8h_1a21d8ea9808e5747a26e6087ec2d6b06f:
.. _cid-ksl_vec3_printwithoptions:
.. _doxid-print_8h_1aa05a9a975b59c9a6bf27ecec8449a2e5:
.. _cid-ksl_vec3f_printwithoptions:
.. _doxid-print_8h_1a37f405f4033a7dea7e36584d09d8e72c:
.. _cid-ksl_mat3x3_printwithoptions:
.. _doxid-print_8h_1a351e0349083c922619b64f0469240d70:
.. _cid-ksl_mat3x3f_printwithoptions:
.. _doxid-print_8h_1a4acdd5c2bc1f906e216210249fadcdb6:
.. _cid-ksl_quaternion_printwithoptions:
.. _doxid-print_8h_1af6b25d8c7e977c23db7dd4f4eaa64116:
.. _cid-ksl_quaternionf_printwithoptions:
.. _doxid-print_8h_1add0cbb8c83901d1407cc66dcbceab5d3:
.. _cid-ksl_screw_printwithoptions:
.. _doxid-print_8h_1a3e90fa8605b43efd26cb4919ad25cb41:
.. _cid-ksl_screwf_printwithoptions:
.. _doxid-print_8h_1a3b89692b25274f60f66c694a8d4a08b2:
.. _cid-ksl_coscrew_printwithoptions:
.. _doxid-print_8h_1acfa7532e7dbc6b1ea0e295e0b5523690:
.. _cid-ksl_coscrewf_printwithoptions:
.. _doxid-print_8h_1a933ad56c37a7c32bbc16d01493d9aee9:
.. _cid-ksl_se3_printwithoptions:
.. _doxid-print_8h_1a9b3a3b8db02d0e06b009874b8e2756ea:
.. _cid-ksl_se3f_printwithoptions:
.. _doxid-print_8h_1aef05a2b9932696b083c99fe034779a7a:
.. _cid-ksl_mat4x4_printwithoptions:
.. _doxid-print_8h_1a643f7f6b882c542b12d216a32ec55aa6:
.. _cid-ksl_mat4x4f_printwithoptions:
.. _doxid-print_8h_1a99d7d3ae0c97a85601d1e2b779625b6c:
.. _cid-ksl_array_printwithoptions:
.. _doxid-print_8h_1ae653bce3512aad269932a5de195524da:
.. _cid-ksl_array2d_printwithoptions:
.. _doxid-print_8h_1aec86b274d27974963ab5b80de7b872b1:
.. _cid-ksl_arrayi_printwithoptions:
.. _doxid-print_8h_1a6c025613bf9e35e9d5ba6e4aec7c2b23:
.. _cid-ksl_triang_printwithoptions:
.. _doxid-print_8h_1ad9826be76b9207d39a01a9dbb8f853a9:
.. _cid-ksl_triangi_printwithoptions:
.. _doxid-print_8h_1a07a6318210cd131facc3cbc180b3ad1a:
.. _cid-ksl_triangb_printwithoptions:
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
.. _doxid-util_8h_1ab56f19d7c8b2d83ad34b23f43dfe58c6:
.. _cid-ksl_allclosei:
.. _doxid-util_8h_1ab083d67beaad577a1f8273910996ca2a:
.. _cid-ksl_arraylerp:
.. _doxid-util_8h_1a64da2905a6a2d7cb1521af05138e0b51:
.. _cid-ksl_arraylerpf:
.. _doxid-vector_8h_1a7c19972f3b88a060bc37371df2e58b7d:
.. _cid-ksl_vec4i:
.. _doxid-vector_8h_1a08e257a47562dc6e060faa7891363e88:
.. _cid-ksl_vec3_l2norm:
.. _doxid-vector_8h_1a19ea31a44f869ce9e065b4a95089532c:
.. _cid-ksl_vec3f_l2norm:
.. _doxid-vector_8h_1ac75b94fd01bd48fdf9c30cc3ae9172a9:
.. _cid-ksl_vec4_l2norm:
.. _doxid-vector_8h_1a791e5a988f602b0c398c98c221c84eb8:
.. _cid-ksl_vec4f_l2norm:
.. _doxid-vector_8h_1a64e470bc534fdc08721184d2aacd9e99:
.. _cid-ksl_vec3_normalize:
.. _doxid-vector_8h_1af64dbf7f6d7490a852007462f1c6d17b:
.. _cid-ksl_vec3f_normalize:
.. _doxid-vector_8h_1a52333541549ee703697a691755091413:
.. _cid-ksl_vec4_normalize:
.. _doxid-vector_8h_1ac9d5a002c1d8f215a01da7d948b007ec:
.. _cid-ksl_vec4f_normalize:
.. _doxid-vector_8h_1a78199b0e4ee4bbbae55c40b8cb4c1200:
.. _cid-ksl_vec3_normalized:
.. _doxid-vector_8h_1a4448b853250e11d79a36797949fcd5a1:
.. _cid-ksl_vec3f_normalized:
.. _doxid-vector_8h_1a00b88f4eb0a002a2ec4a21840d1d3d14:
.. _cid-ksl_vec4_normalized:
.. _doxid-vector_8h_1a6391de001da1de61037cc65d1864005f:
.. _cid-ksl_vec4f_normalized:
.. _doxid-vector_8h_1a16c3485deb9296193dde72899be9da87:
.. _cid-ksl_vec3_scale:
.. _doxid-vector_8h_1a5d096a62536a90df6d0f49f95e0d0a4c:
.. _cid-ksl_vec3f_scale:
.. _doxid-vector_8h_1a89c5b571ee03e1878687b1c57723c5d5:
.. _cid-ksl_vec4_scale:
.. _doxid-vector_8h_1a1a6e1c46bddd0eb4350867b46eba1b4f:
.. _cid-ksl_vec4f_scale:
.. _doxid-vector_8h_1a0b979739da910a4c3da848a5f5ed2f00:
.. _cid-ksl_vec3_scaled:
.. _doxid-vector_8h_1adcc382246306b3097e2c60d18c7394e8:
.. _cid-ksl_vec3f_scaled:
.. _doxid-vector_8h_1ac098278594bdaabd3139ef405997a75c:
.. _cid-ksl_vec4_scaled:
.. _doxid-vector_8h_1ab8e360a3c49fd6c509df3bd84500b014:
.. _cid-ksl_vec4f_scaled:
.. _doxid-vector_8h_1ab46dd6f273814deca232cde08fa8bf95:
.. _cid-ksl_vec3_copy:
.. _doxid-vector_8h_1a785b776d82f4f5b05321769235f202e6:
.. _cid-ksl_vec3f_copy:
.. _doxid-vector_8h_1a22596d87e74def7448df4992c0b702c3:
.. _cid-ksl_vec4_copy:
.. _doxid-vector_8h_1a5aab9f24d582c497c8c4b82ee3c6afad:
.. _cid-ksl_vec4f_copy:
.. _doxid-vector_8h_1a28b58356523d9303869a2ee14aa637bf:
.. _cid-ksl_vec3_swap:
.. _doxid-vector_8h_1ad8260531af3b47874ab7d35819ada2dc:
.. _cid-ksl_vec3f_swap:
.. _doxid-vector_8h_1a7e6bbfba032008d7dfcf6ae98123d8ca:
.. _cid-ksl_vec4_swap:
.. _doxid-vector_8h_1afcfd75bcf9647562007dcd408724f400:
.. _cid-ksl_vec4f_swap:
.. _doxid-vector_8h_1a46e649b51c5d0f86a6ed8c6915193d18:
.. _cid-ksl_vec3_inverted:
.. _doxid-vector_8h_1ab1acc06d157dc058819c1271fd83cb1f:
.. _cid-ksl_vec3_invert:
.. _doxid-vector_8h_1a877225ef397c196915afed0dfc482ccc:
.. _cid-ksl_vec3f_inverted:
.. _doxid-vector_8h_1a2654f6d5ae904f75d156eb7c0ef44ca0:
.. _cid-ksl_vec3f_invert:
.. _doxid-vector_8h_1a0a3c32903e08658f8d605177170f11e0:
.. _cid-ksl_vec4_inverted:
.. _doxid-vector_8h_1a16fcf7f2446c5e5e978b9001a6aaf9f4:
.. _cid-ksl_vec4_invert:
.. _doxid-vector_8h_1a8f6e214555d3334d70f260079a35341b:
.. _cid-ksl_vec4f_inverted:
.. _doxid-vector_8h_1a8c5947e04e37bd74d04aa2a46f7807de:
.. _cid-ksl_vec4f_invert:
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
.. _doxid-vector_8h_1abd9ca7be8f55655be796aec92a86db1a:
.. _cid-ksl_product_avinvf:
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
	typedef struct :ref:`ksl_print_options_t<doxid-structksl__print__options__t>` :ref:`ksl_print_options_t<doxid-print_8h_1a4fda31454cdfc95acbe4d9ac3f8c6197>`
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
	enum :ref:`ksl_matrix_enum_t<doxid-matrix_8h_1adecc9912ee469eb9a01a1c0e4e33cef4>`
	enum :ref:`ksl_print_breakBetweenLines_enum_t<doxid-print_8h_1a66317bd526bb2eaf782419cbb2fef9da>`

	// structs

	struct :ref:`ksl_print_options_t<doxid-structksl__print__options__t>`

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
	union :ref:`ksl_vec4i_t<doxid-unionksl__vec4i__t>`

	// global functions

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`
	:ref:`ksl_axis_getVector<doxid-axis_8h_1aeb4cb5d810cf9f519a2fbfbf11214c1e>` (ksl_axis_enum_t axisType)

	ksl_axis_enum_t
	ksl_axis_enumFromChar (const char*)

	:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`
	:ref:`ksl_coscrew<doxid-coscrew_8h_1a7e6704e2b69caf1cca667b98ef6ba386>` (
	    const double m0,
	    const double m1,
	    const double m2,
	    const double m3,
	    const double m4,
	    const double m5
	    )

	:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`
	:ref:`ksl_coscrewf<doxid-coscrew_8h_1a76c6e24c4466d7e3f1007af523aca93a>` (
	    const float m0,
	    const float m1,
	    const float m2,
	    const float m3,
	    const float m4,
	    const float m5
	    )

	:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`*
	:ref:`ksl_coscrew_alloc<doxid-coscrew_8h_1afeca734953318cffdf39a23afd573825>` (int n)

	:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`*
	:ref:`ksl_coscrewf_alloc<doxid-coscrew_8h_1ab3365b6c870dc61f52af92dd59a55af3>` (int n)

	void
	:ref:`ksl_coscrew_copy<doxid-coscrew_8h_1a822c04f16e9ae5d1d63fa4c52d358c28>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_coscrewf_copy<doxid-coscrew_8h_1a7ceb266571f226b0199fc46bd92a666c>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_coscrew_scale<doxid-coscrew_8h_1a9c0293f849cd72e459eb920e34a83c8c>` (
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* self,
	    const double a
	    )

	void
	:ref:`ksl_coscrewf_scale<doxid-coscrew_8h_1a1290a4c68beb018bc86f49e6ae8ea78c>` (
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self,
	    const float a
	    )

	void
	:ref:`ksl_coscrew_inverted<doxid-coscrew_8h_1adde0d1e7c997c2ad903446a14cdebd1c>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_coscrewf_inverted<doxid-coscrew_8h_1a16aba5a97df44e95d632fa253166c277>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_coscrew_invert<doxid-coscrew_8h_1ad71f0bc9f4c7baa4ed3215db8a6d181c>` (:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* self)

	void
	:ref:`ksl_coscrewf_invert<doxid-coscrew_8h_1ac3f856a46560c8e92d68d91f3f0b0d0f>` (:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self)

	void
	:ref:`ksl_axpy_cc<doxid-coscrew_8h_1abb248fdd9c35689ad7034b94faa372b0>` (
	    const double a,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* x,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* y
	    )

	void
	:ref:`ksl_axpy_ccf<doxid-coscrew_8h_1af12817c5f697e8d030363906622a9da4>` (
	    const float a,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* x,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* y
	    )

	void
	:ref:`ksl_xpy_cc<doxid-coscrew_8h_1ac8637884cf89c41f96f8d2536a381140>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* x,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* y
	    )

	void
	:ref:`ksl_xpy_ccf<doxid-coscrew_8h_1a3aae63afe3e494e5478336efef92eeec>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* x,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* y
	    )

	void
	:ref:`ksl_nxpy_cc<doxid-coscrew_8h_1a26bfc464185b927b9d69eefb247a570a>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* x,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* y
	    )

	void
	:ref:`ksl_nxpy_ccf<doxid-coscrew_8h_1aa48627036b044008b5ae78b6e7728d1b>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* x,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* y
	    )

	void
	:ref:`ksl_product_ca<doxid-coscrew_8h_1ada223e7701cf1454472c3bdd6aeb2a8c>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    const double a,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_caf<doxid-coscrew_8h_1a9575e49d6dc7ddecd6c6ddd64309634a>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    const float a,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_add_cc<doxid-coscrew_8h_1a59dadd311149ae3e5e520185899695f4>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_add_ccf<doxid-coscrew_8h_1a9f13a22010bf04e81391b72b6e0b659c>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_subtract_cc<doxid-coscrew_8h_1a9789cd04fdfd6ba1bb3116e5de7bfb9b>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_subtract_ccf<doxid-coscrew_8h_1a232011f12579ecf2b94f0fe7dbc1ed78>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_cross_cc<doxid-coscrew_8h_1ade4b35932b19f74784e1c86975e8b055>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_cross_ccf<doxid-coscrew_8h_1ae2bdbfdf4104c4230d33aa51ea383128>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdtc<doxid-coscrew_8h_1aea01c281ea5652435836dc9374820d41>` (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdtcf<doxid-coscrew_8h_1a7a3ade7bd8ff468dd63f944247d667c1>` (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdtcinv<doxid-coscrew_8h_1a418fcdb10f1b086d46c22271430c9db3>` (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdtcinvf<doxid-coscrew_8h_1a3929622d53bb5e2de5c3f98e2d660e7f>` (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdrc<doxid-coscrew_8h_1a2849447a782870e7450ff21cdb6b0394>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdrcf<doxid-coscrew_8h_1aa2eaf64d9ad04b1ec95c78fa3cca7139>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdrinvc<doxid-coscrew_8h_1accc4e52ece31b13e54717307669846ec>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdrinvcf<doxid-coscrew_8h_1a7014f00cf6f331b6be58db7415b61ed0>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdc<doxid-coscrew_8h_1ac9cdfbc205413c7057fa54654db46be9>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdcf<doxid-coscrew_8h_1a8be0b50f6087f6d0e4b924127c3664ce>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdinvc<doxid-coscrew_8h_1ad0f1fb989507684b936e917cb35c556f>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

	void
	:ref:`ksl_product_CoAdinvcf<doxid-coscrew_8h_1a24f2cd5aa0326db48165973bc0c53464>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

	:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`
	:ref:`ksl_inertia<doxid-inertia_8h_1ae205178752af78031aa294a2afb2abeb>` (
	    const double m,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t,
	    const double Ixx,
	    const double Iyy,
	    const double Izz,
	    const double Ixy,
	    const double Iyz,
	    const double Izx
	    )

	:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`
	:ref:`ksl_inertiaf<doxid-inertia_8h_1ac5464502b987b6b23ac37d3b354e6534>` (
	    const float m,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t,
	    const float Ixx,
	    const float Iyy,
	    const float Izz,
	    const float Ixy,
	    const float Iyz,
	    const float Izx
	    )

	:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`*
	:ref:`ksl_inertia_alloc<doxid-inertia_8h_1a3bb757d9e15c170aeb46a78f8fea71e7>` (int n)

	:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`*
	:ref:`ksl_inertiaf_alloc<doxid-inertia_8h_1a4636dcf376b3d6cc02ccd5c9fa97a599>` (int n)

	void
	:ref:`ksl_inertia_rotated<doxid-inertia_8h_1a4a387d0c872abcabf269273ba58db901>` (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

	void
	:ref:`ksl_inertiaf_rotated<doxid-inertia_8h_1a1a1e3f03ccf343e0bbae6cf5b5057bf9>` (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

	void
	:ref:`ksl_inertia_rotate<doxid-inertia_8h_1a5143ef0a4aa1f7a701d28388aa8cf1e1>` (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r
	    )

	void
	:ref:`ksl_inertiaf_rotate<doxid-inertia_8h_1a095683dadc83becbf6160d84888bdbd8>` (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r
	    )

	void
	:ref:`ksl_inertia_translated<doxid-inertia_8h_1a0ffd6ef04f8f7abb2901d45fd22daf63>` (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* r,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

	void
	:ref:`ksl_inertiaf_translated<doxid-inertia_8h_1a073ce8555bd68566833b2b7ef95e181e>` (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* r,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

	void
	:ref:`ksl_inertia_translate<doxid-inertia_8h_1a05c6d53f909791b8796bbb4fe909a789>` (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* r
	    )

	void
	:ref:`ksl_inertiaf_translate<doxid-inertia_8h_1a896b52736acad0b43b06d61fac55b99f>` (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* r
	    )

	void
	:ref:`ksl_inertia_transformed<doxid-inertia_8h_1a2e0ddd09114d6e78d0395419dac7d51d>` (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

	void
	:ref:`ksl_inertiaf_transformed<doxid-inertia_8h_1adcaf2a48154f2ab93b1c88fb0a655992>` (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

	void
	:ref:`ksl_inertia_transform<doxid-inertia_8h_1ad0490956ce03ec5eb1de20e11af52505>` (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d
	    )

	void
	:ref:`ksl_inertiaf_transform<doxid-inertia_8h_1a9e1b20d519877020a4fd52a447ba0d9c>` (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d
	    )

	void
	:ref:`ksl_inertia_merge<doxid-inertia_8h_1aaa8803a3a2c64f1c85035bb525c1db63>` (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t_ic_i,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_j,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t_jc_j,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D_ij
	    )

	void
	:ref:`ksl_inertiaf_merge<doxid-inertia_8h_1ad2a5726ed9a42f28903084ae99eac1ca>` (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t_ic_i,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_j,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t_jc_j,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D_ij
	    )

	int
	:ref:`ksl_inertia_factor<doxid-inertia_8h_1a4d826f10adde0189c80e4018a4114ab2>` (:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`*)

	int
	:ref:`ksl_inertiaf_factor<doxid-inertia_8h_1a9a7a767bc2e0caf961f4fb1689fbfc11>` (:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`*)

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

	int
	ksl_linalg_lu_full_rmo (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    const double eps,
	    int* pr,
	    int* pc
	    )

	int
	ksl_linalg_lu_full_specified_rmo (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    double eps,
	    int* pr,
	    int* pc,
	    const int specifiedIndex
	    )

	void
	ksl_linalg_lu_rmo (
	    const int rank,
	    const int colDim,
	    double* A
	    )

	void
	ksl_linalg_lu_setBMatrix_rmo (
	    const int rowDim,
	    const int colDim,
	    const int rank,
	    double* A
	    )

	void
	:ref:`ksl_linalg_lu_setCMatrix_rmo<doxid-linalg_8h_1a50a42897bbde4b0b692f73c9340c846e>` (
	    int rowDim,
	    int colDim,
	    int rank,
	    double* A
	    )

	int
	ksl_linalg_ldlt_rmo (
	    double* A,
	    const int n
	    )

	int
	ksl_linalg_cholesky_rmo (
	    double* A,
	    const int n
	    )

	void
	ksl_linalg_ldlt_forwardElimination_rmo (
	    const double* L,
	    const double* b,
	    double* y,
	    const int n
	    )

	void
	ksl_linalg_ldlt_backwardSubstitution_rmo (
	    const double* L,
	    const double* b,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_cholesky_forwardElimination_rmo (
	    const double* L,
	    const double* b,
	    double* y,
	    const int n
	    )

	void
	ksl_linalg_cholesky_backwardSubstitution_rmo (
	    const double* L,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_ldlt_solve_rmo (
	    const double* A,
	    const double* b,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_cholesky_solve_rmo (
	    const double* A,
	    const double* b,
	    double* x,
	    const int n
	    )

	int
	ksl_linalg_symmetricMatrixInverse_rmo (
	    double* A,
	    const int n
	    )

	int
	ksl_linalg_lu_full_cmo (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    const double eps,
	    int* pr,
	    int* pc
	    )

	int
	ksl_linalg_lu_full_specified_cmo (
	    const int rowDim,
	    const int colDim,
	    double* A,
	    double eps,
	    int* pr,
	    int* pc,
	    const int specifiedIndex
	    )

	void
	ksl_linalg_lu_cmo (
	    const int rank,
	    const int colDim,
	    double* A
	    )

	void
	ksl_linalg_lu_setBMatrix_cmo (
	    const int rowDim,
	    const int colDim,
	    const int rank,
	    double* A
	    )

	void
	:ref:`ksl_linalg_lu_setCMatrix_cmo<doxid-linalg_8h_1a0f4d5fe5074266d025a4c900ba95ab34>` (
	    int rowDim,
	    int colDim,
	    int rank,
	    double* A
	    )

	int
	ksl_linalg_ldlt_cmo (
	    double* A,
	    const int n
	    )

	int
	ksl_linalg_cholesky_cmo (
	    double* A,
	    const int n
	    )

	void
	ksl_linalg_ldlt_forwardElimination_cmo (
	    const double* L,
	    const double* b,
	    double* y,
	    const int n
	    )

	void
	ksl_linalg_ldlt_backwardSubstitution_cmo (
	    const double* L,
	    const double* b,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_cholesky_forwardElimination_cmo (
	    const double* L,
	    const double* b,
	    double* y,
	    const int n
	    )

	void
	ksl_linalg_cholesky_backwardSubstitution_cmo (
	    const double* L,
	    const double* y,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_ldlt_solve_cmo (
	    const double* A,
	    double*const b,
	    double* x,
	    const int n
	    )

	void
	ksl_linalg_cholesky_solve_cmo (
	    const double* A,
	    const double* b,
	    double* x,
	    const int n
	    )

	int
	ksl_linalg_symmetricMatrixInverse_cmo (
	    double* A,
	    const int n
	    )

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	:ref:`ksl_SE3<doxid-matrix_8h_1af666448ab4ee33d60df0f1a06bc2200f>` (
	    const double m00,
	    const double m01,
	    const double m02,
	    const double m03,
	    const double m10,
	    const double m11,
	    const double m12,
	    const double m13,
	    const double m20,
	    const double m21,
	    const double m22,
	    const double m23
	    )

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	:ref:`ksl_SE3_cmo<doxid-matrix_8h_1a36fbb29343e99dba5df354e77e757f85>` (
	    const double m00,
	    const double m10,
	    const double m20,
	    const double m01,
	    const double m11,
	    const double m21,
	    const double m02,
	    const double m12,
	    const double m22,
	    const double m03,
	    const double m13,
	    const double m23
	    )

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	:ref:`ksl_SE3_fromRt<doxid-matrix_8h_1a897f5a11eaa0b29c6f8c4d1b6ae49e62>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t
	    )

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	:ref:`ksl_SE3f<doxid-matrix_8h_1a50d5e14c3f8018c3af19d871a1c9bb77>` (
	    const float m00,
	    const float m01,
	    const float m02,
	    const float m03,
	    const float m10,
	    const float m11,
	    const float m12,
	    const float m13,
	    const float m20,
	    const float m21,
	    const float m22,
	    const float m23
	    )

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	:ref:`ksl_SE3f_cmo<doxid-matrix_8h_1a99ac89949a852c61a95469d0bf4d5c78>` (
	    const float m00,
	    const float m10,
	    const float m20,
	    const float m01,
	    const float m11,
	    const float m21,
	    const float m02,
	    const float m12,
	    const float m22,
	    const float m03,
	    const float m13,
	    const float m23
	    )

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	:ref:`ksl_SE3f_fromRt<doxid-matrix_8h_1a79a05080dd8d7e2209b88407709b8291>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` R,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t
	    )

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`
	:ref:`ksl_mat3x3<doxid-matrix_8h_1a0e09e8029123d8a95841902e7219a38f>` (
	    const double m00,
	    const double m01,
	    const double m02,
	    const double m10,
	    const double m11,
	    const double m12,
	    const double m20,
	    const double m21,
	    const double m22
	    )

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`
	:ref:`ksl_mat3x3_cmo<doxid-matrix_8h_1ab01f7b905575b766ec35f40f429c7959>` (
	    const double m00,
	    const double m10,
	    const double m20,
	    const double m01,
	    const double m11,
	    const double m21,
	    const double m02,
	    const double m12,
	    const double m22
	    )

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`
	:ref:`ksl_mat3x3f<doxid-matrix_8h_1a80ce314c95c171740b1b4feac8d8bfd5>` (
	    const float m00,
	    const float m01,
	    const float m02,
	    const float m10,
	    const float m11,
	    const float m12,
	    const float m20,
	    const float m21,
	    const float m22
	    )

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`
	:ref:`ksl_mat3x3f_cmo<doxid-matrix_8h_1a6ae8fa1bac40407770007cee2d0fe716>` (
	    const float m00,
	    const float m10,
	    const float m20,
	    const float m01,
	    const float m11,
	    const float m21,
	    const float m02,
	    const float m12,
	    const float m22
	    )

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	:ref:`ksl_mat4x4<doxid-matrix_8h_1a31fe657a2f227b1b39b165036a804af7>` (
	    const double m00,
	    const double m01,
	    const double m02,
	    const double m03,
	    const double m10,
	    const double m11,
	    const double m12,
	    const double m13,
	    const double m20,
	    const double m21,
	    const double m22,
	    const double m23,
	    const double m30,
	    const double m31,
	    const double m32,
	    const double m33
	    )

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	:ref:`ksl_mat4x4_cmo<doxid-matrix_8h_1ab7402f404bfeab3b78df60d9cebc4c91>` (
	    const double m00,
	    const double m10,
	    const double m20,
	    const double m30,
	    const double m01,
	    const double m11,
	    const double m21,
	    const double m31,
	    const double m02,
	    const double m12,
	    const double m22,
	    const double m32,
	    const double m03,
	    const double m13,
	    const double m23,
	    const double m33
	    )

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	:ref:`ksl_mat4x4_fromSE3<doxid-matrix_8h_1ab8e242f75d2051b81d34f595dc7b264d>` (const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>` D)

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	:ref:`ksl_mat4x4_fromRt<doxid-matrix_8h_1a333f3c1c1c0e98361dfcf5be39615a76>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t
	    )

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	:ref:`ksl_mat4x4f<doxid-matrix_8h_1afbec2c12728678a3246ec2daa619a5bb>` (
	    const float m00,
	    const float m01,
	    const float m02,
	    const float m03,
	    const float m10,
	    const float m11,
	    const float m12,
	    const float m13,
	    const float m20,
	    const float m21,
	    const float m22,
	    const float m23,
	    const float m30,
	    const float m31,
	    const float m32,
	    const float m33
	    )

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	:ref:`ksl_mat4x4f_cmo<doxid-matrix_8h_1a647ff06db64c2bd395833206bdb2a28f>` (
	    const float m00,
	    const float m10,
	    const float m20,
	    const float m30,
	    const float m01,
	    const float m11,
	    const float m21,
	    const float m31,
	    const float m02,
	    const float m12,
	    const float m22,
	    const float m32,
	    const float m03,
	    const float m13,
	    const float m23,
	    const float m33
	    )

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	:ref:`ksl_mat4x4f_fromSE3f<doxid-matrix_8h_1a49718c56c37ca9853352797d58011334>` (const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>` D)

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	:ref:`ksl_mat4x4f_fromRt<doxid-matrix_8h_1a7c1f0a47c2f163c5a82f9b1c2dde1fa0>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` R,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t
	    )

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`*
	:ref:`ksl_SE3_alloc<doxid-matrix_8h_1afab63dbe2c5fc22414b3640121c2f1f6>` (int n)

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`*
	:ref:`ksl_SE3f_alloc<doxid-matrix_8h_1a396ee8308a34a141b90808ab29ec77d2>` (int n)

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*
	:ref:`ksl_mat3x3_alloc<doxid-matrix_8h_1adb10d5d179d7efa909f625e149d06dc2>` (int n)

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*
	:ref:`ksl_mat3x3f_alloc<doxid-matrix_8h_1ab67edb3d44f67460dbe370cb00e47d6a>` (int n)

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`*
	:ref:`ksl_mat4x4_alloc<doxid-matrix_8h_1a95acc179f532a4e27d0e86c8cd73b61a>` (int n)

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`*
	:ref:`ksl_mat4x4f_alloc<doxid-matrix_8h_1a23bca8091b743f378484b049ea1cfeb0>` (int n)

	void
	:ref:`ksl_SE3_toMat4x4<doxid-matrix_8h_1abe0d938eae89c1165e49792df6320f5c>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* m
	    )

	void
	:ref:`ksl_SE3f_toMat4x4f<doxid-matrix_8h_1ab752ddf0d405c49c8217cfca6aeab93c>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d,
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* m
	    )

	void
	:ref:`ksl_SE3_toMat4x4f<doxid-matrix_8h_1ace3abb7ded8d1a7a3068ab36faf23fa6>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* m
	    )

	void
	:ref:`ksl_dc<doxid-matrix_8h_1a9df9a1b57722f5dadc0f342a0b37c7a5>` (
	    const double thetai,
	    double dc [2]
	    )

	void
	:ref:`ksl_dcf<doxid-matrix_8h_1a471044a6f1f405d9518e8ef9108aa978>` (
	    const float thetai,
	    float dc [2]
	    )

	void
	:ref:`ksl_SE3_setIdentity<doxid-matrix_8h_1a1e586c05382ebb177e18490fba4f738c>` (:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d)

	void
	:ref:`ksl_SE3f_setIdentity<doxid-matrix_8h_1add2f0dbc6d29b0b1695100a262d8ca69>` (:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d)

	void
	:ref:`ksl_mat3x3_setIdentity<doxid-matrix_8h_1ab58fb659ed34589b759a9bff7257f9c0>` (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r)

	void
	:ref:`ksl_mat3x3f_setIdentity<doxid-matrix_8h_1a81ad7fbd8db8e8464cf7a96c8d87df09>` (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r)

	void
	:ref:`ksl_mat3x3_set<doxid-matrix_8h_1a214b4ee953af0437c415341ac20ba7c9>` (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const int row,
	    const int column,
	    const double value
	    )

	void
	:ref:`ksl_mat4x4_set<doxid-matrix_8h_1a7e4178be19e7ab6820de2aed88a11f08>` (
	    :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* R,
	    const int row,
	    const int column,
	    const double value
	    )

	void
	:ref:`ksl_SE3_set<doxid-matrix_8h_1ae4000f58b12ee4202a1851aebbcb4a3d>` (
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    const int row,
	    const int column,
	    const double value
	    )

	void
	:ref:`ksl_SE3f_set<doxid-matrix_8h_1aa263ec13c47bf19dfcb646fb3ac8e40d>` (
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    const int row,
	    const int column,
	    const float value
	    )

	void
	:ref:`ksl_mat3x3_setFromVectors<doxid-matrix_8h_1a2f0629a91c545f60a49380a74ce1bf46>` (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* x,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* y,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* z
	    )

	void
	:ref:`ksl_mat3x3f_setFromVectors<doxid-matrix_8h_1a340c64a953a994d665382361a29229f0>` (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* x,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* y,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* z
	    )

	void
	:ref:`ksl_mat3x3f_set<doxid-matrix_8h_1a826c58e7955ed694952468b334e42d79>` (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    int row,
	    int column,
	    float value
	    )

	void
	:ref:`ksl_mat4x4f_set<doxid-matrix_8h_1aca485e889183d9468d741f5a1f347ed4>` (
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* D,
	    int row,
	    int column,
	    float value
	    )

	void
	:ref:`ksl_mat4x4_setIdentity<doxid-matrix_8h_1a1e0dc7d0fc1151b7a90d1b2b25cf7cbc>` (:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* M)

	void
	:ref:`ksl_mat4x4f_setIdentity<doxid-matrix_8h_1afba7a831dd92d569b81b9a0cdcefda83>` (:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* M)

	double
	:ref:`ksl_SE3_get<doxid-matrix_8h_1abd65fe3a5e53ee802e2dababa95c3dc4>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    const int row,
	    const int column
	    )

	double
	:ref:`ksl_mat3x3_get<doxid-matrix_8h_1a83192ca3ace3ddb96906cf0ec071cc86>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const int row,
	    const int column
	    )

	float
	:ref:`ksl_mat3x3f_get<doxid-matrix_8h_1a7e9dfa7888842a24a24805cebef9459e>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    const int row,
	    const int column
	    )

	float
	:ref:`ksl_SE3f_get<doxid-matrix_8h_1ac1a8a1a5bab85a4c524449e00e5e00e1>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    const int row,
	    const int column
	    )

	void
	:ref:`ksl_SE3_getTranslation<doxid-matrix_8h_1a8154daa30091f68b1ffb62e2a3cb70a1>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t
	    )

	void
	:ref:`ksl_SE3f_getTranslation<doxid-matrix_8h_1a6c06836476402348d2fd554a5db26050>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t
	    )

	void
	:ref:`ksl_mat3x3_copy<doxid-matrix_8h_1a659e01255e0bc4624033464e2e7182ca>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_mat3x3f_copy<doxid-matrix_8h_1a0008a609192b6e2e9019d3634b15f6ad>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	int
	:ref:`ksl_mat3x3_invert<doxid-matrix_8h_1a6223f5408884301ff82ee0c66fcf1ed2>` (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R)

	int
	:ref:`ksl_mat3x3f_invert<doxid-matrix_8h_1a57f7021c15401bdcdc84a63eb3ccb572>` (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R)

	int
	:ref:`ksl_mat3x3_inverted<doxid-matrix_8h_1a621d2689e4aa351e111b29c9b1140819>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	int
	:ref:`ksl_mat3x3f_inverted<doxid-matrix_8h_1a3f8fbfc673692d574540a3062c1a0c57>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_mat3x3_transpose<doxid-matrix_8h_1a264c29f922f7813d256773dcc33b3138>` (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R)

	void
	:ref:`ksl_mat3x3f_transpose<doxid-matrix_8h_1aa6d90d88f07f34c037e3f846b5de8271>` (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R)

	void
	:ref:`ksl_mat3x3_transposed<doxid-matrix_8h_1a4fa0f7ec6a937a375afdb9865574fecc>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_mat3x3f_transposed<doxid-matrix_8h_1aa5574ade523fa581161cfc09b5204a05>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_SE3_invert<doxid-matrix_8h_1aca804b2c785d9f036446df45beababae>` (:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D)

	void
	:ref:`ksl_SE3f_invert<doxid-matrix_8h_1ac05052c4b6660087dc45c399a1bf498d>` (:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D)

	void
	:ref:`ksl_SE3_inverted<doxid-matrix_8h_1a1bb0f88b0a2aa12c88364e10817a6374>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_SE3f_inverted<doxid-matrix_8h_1a883d826184c26412ceddfab0f5bc97a4>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_SE3_copy<doxid-matrix_8h_1ad872da8f3834ab436e0388de6134fd2f>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_SE3f_copy<doxid-matrix_8h_1a182b96d3aaed5e6ba17eb15748dd7a1a>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_mat3x3_getEulerAnglesWithReference<doxid-matrix_8h_1a99c973220c97d334acefb30e0706ed9b>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    const ksl_axis_enum_t axisType,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* angles,
	    ...
	    )

	void
	:ref:`ksl_mat3x3f_getEulerAnglesWithReference<doxid-matrix_8h_1a75ed791c7dc1d6a6cbb0319e4e2b493a>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    const ksl_axis_enum_t axisType,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* angles,
	    ...
	    )

	void
	:ref:`ksl_mat3x3_setFromEulerAngles<doxid-matrix_8h_1a1d998186da1242f36e0d3c1b26073239>` (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    const ksl_axis_enum_t axisType,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* angles
	    )

	void
	:ref:`ksl_mat3x3f_setFromEulerAngles<doxid-matrix_8h_1a39aacd9b358f91bcf9ca414892f5d0fc>` (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    const ksl_axis_enum_t axisType,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* angles
	    )

	void
	:ref:`ksl_mat3x3_getAxisAngle<doxid-matrix_8h_1a21b4e9dad800701badf4a4ae20e9e888>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*,
	    double*
	    )

	void
	:ref:`ksl_mat3x3_setFromAxisAngle<doxid-matrix_8h_1a305b61035160d778913d6512475f469f>` (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*,
	    const double
	    )

	void
	:ref:`ksl_mat3x3f_getAxisAngle<doxid-matrix_8h_1af9e7adb94891fcb280e68a475e049000>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*,
	    float*
	    )

	void
	:ref:`ksl_mat3x3f_setFromAxisAngle<doxid-matrix_8h_1a909d6e045fbf9be40b47dcca564d18de>` (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*,
	    const float
	    )

	void
	:ref:`ksl_mat4x4_getTranslation<doxid-matrix_8h_1a655d343e8889959a198bd3055c8c0d7c>` (
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* Mi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

	void
	:ref:`ksl_mat4x4f_getTranslation<doxid-matrix_8h_1a2d6b59053e391cf62311fcb6bf71081d>` (
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* Mi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

	double
	:ref:`ksl_mat4x4_get<doxid-matrix_8h_1ab9d90e415397b467f5fbf24d63593913>` (
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* Mi,
	    const int row,
	    const int column
	    )

	float
	:ref:`ksl_mat4x4f_get<doxid-matrix_8h_1aaacb3f73b5db33f0259007ea185d6a22>` (
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* Mi,
	    const int row,
	    const int column
	    )

	double
	:ref:`ksl_mat3x3_determinant<doxid-matrix_8h_1a9c6c8a3db26680b4aa525c5253a950ee>` (const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*)

	float
	:ref:`ksl_mat3x3f_determinant<doxid-matrix_8h_1a19d646584d71bdbf25ec817c3bb10468>` (const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*)

	void
	:ref:`ksl_product_drv<doxid-matrix_8h_1a403d3115123b4f76a6f27ec5ca7ce274>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvf<doxid-matrix_8h_1aecf5aac9412aa19ae834d319ebd98ea5>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvinv<doxid-matrix_8h_1a5b7eee293303e16c8231e8afefcbd264>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvinvf<doxid-matrix_8h_1aafcb94ac1cdfccb9971afbe83469ee48>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drinvv<doxid-matrix_8h_1a6f03fffadeea016f79b189a676ef6590>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drinvvf<doxid-matrix_8h_1aa4c9340e1679402e966641529aef2dd5>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drinvvinv<doxid-matrix_8h_1a512dbc30bc144e22d84b0ebcb467ee99>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drinvvinvf<doxid-matrix_8h_1acfca5a948a1b891c67fbabe61afb4f82>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtx<doxid-matrix_8h_1a74533c22448aa1778ff734d287931ff5>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtxf<doxid-matrix_8h_1a895ddfe07eb888ed3d287a6da0d21b98>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtxinv<doxid-matrix_8h_1ac6c6d0870043eae9ac8d21170ac0f35e>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtxinvf<doxid-matrix_8h_1a20e95b864ae594011833dc0b2d58bb33>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvty<doxid-matrix_8h_1a77fc0964e58b852eb9849fdc98500853>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtyf<doxid-matrix_8h_1adaed020b38a6b59f2b3ca909b134ab33>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtyinv<doxid-matrix_8h_1af0db5c28061626299de279551fdf1448>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtyinvf<doxid-matrix_8h_1a528e7cf7dd8657c1c16b2476c8e3180b>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtz<doxid-matrix_8h_1a382179892501b2ca11749f8dabfff479>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtzf<doxid-matrix_8h_1afea0117039f42f40c2f5a20cbeca8682>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtzinv<doxid-matrix_8h_1a3c25a5ad0517dddf6459876b6a2aded7>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_drvtzinvf<doxid-matrix_8h_1a156424d82a2ec1821ddfa518de21fbdb>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_drdrx<doxid-matrix_8h_1ab28fd58fa54787c6d00e8583551f269b>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrxf<doxid-matrix_8h_1a841e4404e3180416561d1eb85f42f752>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrxinv<doxid-matrix_8h_1a0f8147a0eccde2ea280f9cedf0161e41>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrxinvf<doxid-matrix_8h_1a035330469bffd88388cde0b7531b1fdd>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdry<doxid-matrix_8h_1a42eb97c1b223820a1e6786e8c84a1cc6>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdryf<doxid-matrix_8h_1ac76d6dfd9d92929ef94bbe1a35e5ef6c>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdryinv<doxid-matrix_8h_1a7ce0d67d2bdc0d81bba7b63505a4bbaa>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdryinvf<doxid-matrix_8h_1a75538fc1a0894a5281ae9b9aa4747550>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrz<doxid-matrix_8h_1ad8de4524273920c39c60a682f59def10>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrzf<doxid-matrix_8h_1aa1968e258d20b175fb2c51bef32862d3>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrzinv<doxid-matrix_8h_1a63f176e05ec89befa6cae43281273888>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrzinvf<doxid-matrix_8h_1a87876bb5e6f36dfb32832cb59cd59386>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdr<doxid-matrix_8h_1a9909e2688e96649fc489d4146cf76309>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrf<doxid-matrix_8h_1a4a10bf67a02e33862201f67be3d1e306>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrinv<doxid-matrix_8h_1a8ab8a0fa93f7904f1383a2bd1c43d383>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drdrinvf<doxid-matrix_8h_1a61401166bb323fb690f17fb057b3fabc>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_drinvdr<doxid-matrix_8h_1ac7c3eb3a0a483c04849d5400f83346f7>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

	void
	:ref:`ksl_product_drinvdrf<doxid-matrix_8h_1afdc3dbfcdeb378dee0d302a95ed1878e>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

	void
	:ref:`ksl_product_dv<doxid-matrix_8h_1a89cbbe54e33d39734fad9eaf019938c1>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_dvf<doxid-matrix_8h_1aae4ed7f97b099b5a91a9897df215a568>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_dinvv<doxid-matrix_8h_1a4fd6871e4bd4853ddb181bc77f40db5c>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	:ref:`ksl_product_dinvvf<doxid-matrix_8h_1a27206827f2ee969f15c7bc77d059c41a>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	:ref:`ksl_product_ddrx<doxid-matrix_8h_1a89fbbfddfa9b023c8bf59dce0f515ee6>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrxf<doxid-matrix_8h_1a9cc272be249bbf2610fedf23f70f5b7d>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrxinv<doxid-matrix_8h_1af0fe4b62b1ae13c590bec8be64771d78>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrxinvf<doxid-matrix_8h_1a95c46420eca8e31fcd7b76d41fe1143f>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddry<doxid-matrix_8h_1a954264c1bc3a4e8e47e63c2682bb9090>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddryf<doxid-matrix_8h_1a4302352cde9ca58fa87f55d93996fe9a>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddryinv<doxid-matrix_8h_1afd619afd47692e36a9cad186fee6b687>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddryinvf<doxid-matrix_8h_1ac26fbb7270a979e832ca699ce627644b>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrz<doxid-matrix_8h_1a904407cfe285833aa9f070cc55e7a56e>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrzf<doxid-matrix_8h_1af2a48c5e14b9e2ce6a6c4d77d2dbffac>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrzinv<doxid-matrix_8h_1ad08885ba5969c6662ce36aeec35e0680>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrzinvf<doxid-matrix_8h_1a2d1255d8074162eef6a5a3a8f2f8284d>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddt<doxid-matrix_8h_1ada7fc5c86c16b78c6c11c98861001d60>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtinv<doxid-matrix_8h_1a9fe2fb618bf2b59cba070eae4e6e1df2>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtinvf<doxid-matrix_8h_1aa06b5083a440f16f73d94544c058859f>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtf<doxid-matrix_8h_1a27b001c3020cbedebacb8498b3e03a0e>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_dinvdt<doxid-matrix_8h_1a2010a2f24e1da281d83db9f9f9e583cb>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_dinvdtf<doxid-matrix_8h_1a1784236b926c17bf09e0ab65c2869585>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtx<doxid-matrix_8h_1a7efab3193f502c06f891011536e129dd>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtxf<doxid-matrix_8h_1a450a2ffc23fe16f65b453871e5e93e8e>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtxinv<doxid-matrix_8h_1a3fabcec659331aa080eeff02bb77a195>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtxinvf<doxid-matrix_8h_1a49c127a19375005dd3dcf0db8a5f154c>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddty<doxid-matrix_8h_1a868400ded32600cc2e983dbc9eb701c1>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtyf<doxid-matrix_8h_1a7ee9767dfdf20e08d8b1128643d3b8c0>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtyinv<doxid-matrix_8h_1a2d309b34086fe456701e99053a5fa5d5>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtyinvf<doxid-matrix_8h_1a737c7b541ba23d0f3fc924115a04b646>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtz<doxid-matrix_8h_1ad2ee354edcf8f508911f9626c042a8f5>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtzf<doxid-matrix_8h_1afce7b27ccf0cdbdb464d4dde33de0925>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtzinv<doxid-matrix_8h_1a788d88150cac3e051989b2ec9136890d>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddtzinvf<doxid-matrix_8h_1a8e10978354a96dac2d83345517992870>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddr<doxid-matrix_8h_1aa9c8e7bdfb33c1bf5399056e863a43a5>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrf<doxid-matrix_8h_1af902cbe4b9c0e2747f285607e352cc92>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrinv<doxid-matrix_8h_1a4539c07a76339e8f140dbb84e26fe60d>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddrinvf<doxid-matrix_8h_1a5cd6901393ac24ac3926834a39ef8d52>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_dd<doxid-matrix_8h_1a15bcf0d47792c422bf2a37776d8fedf1>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D1i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D2i,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddf<doxid-matrix_8h_1af3efc7b072d4ee61ec9e32934a567a52>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D1i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D2i,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_product_ddinv<doxid-matrix_8h_1a0212b856cf24880d5a12f019dfee91bc>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D1i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D2i,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

	void
	:ref:`ksl_product_ddinvf<doxid-matrix_8h_1aa551d477178695b29bd4732f0cf8f3f8>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D1i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D2i,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

	void
	:ref:`ksl_print_setDefaultOptions<doxid-print_8h_1a2e5a1bcddc0e22def85af860db77f310>` ()

	void
	:ref:`ksl_print_setDelimiterOption<doxid-print_8h_1a98672fb59441c141cf749f99cb97235c>` (
	    const char* delimiter,
	    ...
	    )

	void
	:ref:`ksl_print_setRealFormatOption<doxid-print_8h_1ac163ab31d913a151c3bde009e3d8918e>` (
	    const char* fmt,
	    ...
	    )

	void
	:ref:`ksl_print_setInnerBracketsOption<doxid-print_8h_1ad0388b97e6c0a0393eaac3fe964bfa95>` (
	    const char* left,
	    const char* right,
	    ...
	    )

	void
	:ref:`ksl_print_setOuterBracketsOption<doxid-print_8h_1a955148cf4e975318b12ec9c9498af32d>` (
	    const char* left,
	    const char* right,
	    ...
	    )

	void
	:ref:`ksl_print_setBreakBetweenLinesInMatrixOption<doxid-print_8h_1a958c8cba13c82587a113946b0ddbad9a>` (
	    ksl_print_breakBetweenLines_enum_t val,
	    ...
	    )

	void
	:ref:`ksl_print_setBooleanOption<doxid-print_8h_1a2375c5f944ce34ebe337d14c6522528e>` (
	    const char* True,
	    const char* False,
	    ...
	    )

	void
	:ref:`ksl_print_setRowColumnMajorPrintingOption<doxid-print_8h_1a39ae1ab349f68f28957f6c7f74f2c117>` (
	    ksl_matrix_enum_t print_row_column_major,
	    ...
	    )

	:ref:`ksl_print_options_t<doxid-structksl__print__options__t>`*
	:ref:`ksl_print_options<doxid-print_8h_1abc715dd84d5ef70c8936ba2afc5615b4>` ()

	void
	ksl_vec3_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v,
	    ...
	    )

	void
	ksl_vec3f_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    ...
	    )

	void
	ksl_mat3x3_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* m,
	    ...
	    )

	void
	ksl_mat3x3f_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* m,
	    ...
	    )

	void
	ksl_quaternion_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_quaternion_t<doxid-unionksl__quaternion__t>`* q,
	    ...
	    )

	void
	ksl_quaternionf_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_quaternionf_t<doxid-unionksl__quaternionf__t>`* q,
	    ...
	    )

	void
	ksl_screw_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s,
	    ...
	    )

	void
	ksl_screwf_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s,
	    ...
	    )

	void
	ksl_coscrew_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* s,
	    ...
	    )

	void
	ksl_coscrewf_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* s,
	    ...
	    )

	void
	ksl_SE3_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    ...
	    )

	void
	ksl_SE3f_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* r,
	    ...
	    )

	void
	ksl_mat4x4_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* d,
	    ...
	    )

	void
	ksl_mat4x4f_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* d,
	    ...
	    )

	void
	ksl_array_printWithOptions (
	    FILE* f,
	    const int n,
	    const double* a,
	    ...
	    )

	void
	ksl_array2D_printWithOptions (
	    FILE* f,
	    const int rowDim,
	    const int colDim,
	    const double* a,
	    ...
	    )

	void
	ksl_arrayi_printWithOptions (
	    FILE* f,
	    const int n,
	    const int* a,
	    ...
	    )

	void
	ksl_triang_printWithOptions (
	    FILE* f,
	    const int n,
	    const double* a,
	    ...
	    )

	void
	ksl_triangi_printWithOptions (
	    FILE* f,
	    const int n,
	    const int* a,
	    ...
	    )

	void
	ksl_triangb_printWithOptions (
	    FILE* f,
	    const int n,
	    const bool* a,
	    ...
	    )

	void
	:ref:`ksl_inertia_printWithOptions<doxid-print_8h_1a620f9daa7305bf5d1c08da8b816201be>` (
	    FILE* f,
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* m,
	    ...
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

	:ref:`ksl_screw_t<doxid-unionksl__screw__t>`
	:ref:`ksl_screw<doxid-screw_8h_1a074aa263bdba2e806f41b8c0fd70b049>` (
	    const double m0,
	    const double m1,
	    const double m2,
	    const double m3,
	    const double m4,
	    const double m5
	    )

	:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`
	:ref:`ksl_screwf<doxid-screw_8h_1a47ed7eeed2d9f65a783981f5f7af27e3>` (
	    const float m0,
	    const float m1,
	    const float m2,
	    const float m3,
	    const float m4,
	    const float m5
	    )

	:ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	:ref:`ksl_screw_alloc<doxid-screw_8h_1a4ee1e17a87eb36a6d46ea6b11207f1f1>` (int n)

	:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	:ref:`ksl_screwf_alloc<doxid-screw_8h_1a8b961eb4dc4f53561129118e64978b32>` (int n)

	double
	:ref:`ksl_screw_norm<doxid-screw_8h_1aff240f06e66c05e2c67bef3296110d01>` (const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s)

	float
	:ref:`ksl_screwf_norm<doxid-screw_8h_1a183da8324398b1c29254ad6038a04ea6>` (const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s)

	void
	:ref:`ksl_screw_normalize<doxid-screw_8h_1af7e64780709d753afc65964a29b2d202>` (:ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s)

	void
	:ref:`ksl_screwf_normalize<doxid-screw_8h_1a34cae9d994d45ddeb3350f721a653939>` (:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s)

	void
	:ref:`ksl_screw_normalized<doxid-screw_8h_1aba24696734f91f274a313fcded239a9f>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_screwf_normalized<doxid-screw_8h_1a331cf06b3df89b266aefc72ec88b51cb>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	double
	:ref:`ksl_dot_cs<doxid-screw_8h_1a1e16e01205618ecbb97ce9354a064eb5>` (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si
	    )

	float
	:ref:`ksl_dot_csf<doxid-screw_8h_1a6573ab37452003260c07690964c1d5aa>` (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si
	    )

	void
	:ref:`ks_screw_scale<doxid-screw_8h_1ace8288864ae74b66f23d5c80d8e32e36>` (
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`,
	    const double
	    )

	void
	:ref:`ks_screwf_scale<doxid-screw_8h_1acb56e1c2c428883359aa0bd2186d6ff3>` (
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`,
	    const float
	    )

	void
	:ref:`ksl_screw_copy<doxid-screw_8h_1a5c6f25b9ffae60a91a462cda40136fa7>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_screwf_copy<doxid-screw_8h_1a9b38f6219c0b2ad9504d5d1a9c7c652f>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_screw_invert<doxid-screw_8h_1a3b1aea456f3d39464b038afc44fb97f1>` (:ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si)

	void
	:ref:`ksl_screwf_invert<doxid-screw_8h_1a6405e06d36986bdcd43fce3084c24461>` (:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si)

	void
	:ref:`ksl_screw_inverted<doxid-screw_8h_1aa2765f5d941bc8d85286a06ba74f3669>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_screwf_inverted<doxid-screw_8h_1a0009bdfe7542a64fc2383d193c8c202d>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_as<doxid-screw_8h_1a9b90bf999e5c58cfcb8c238a68a99771>` (
	    const double k,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_asf<doxid-screw_8h_1a820e13bbb612f278942f5a71ef24f9ab>` (
	    const float k,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_axpy_ss<doxid-screw_8h_1abcab2c37336344271936eca5eebd07b7>` (
	    const double,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	void
	:ref:`ksl_axpy_ssf<doxid-screw_8h_1ade69b9088fef0ec2689b3c9ce60472f7>` (
	    const float,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	:ref:`ksl_xpy_ss<doxid-screw_8h_1a030fb18f21d0e205b91e9a43fa72952e>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	void
	:ref:`ksl_xpy_ssf<doxid-screw_8h_1a3c7c48bc899eec2ba4d654316e860f8b>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	:ref:`ksl_nxpy_ss<doxid-screw_8h_1aed7ec16489a53e348a93db9e61e4302e>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

	void
	:ref:`ksl_nxpy_ssf<doxid-screw_8h_1a06f69525c025aff9c5ad730dfd4d1441>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

	void
	:ref:`ksl_add_ss<doxid-screw_8h_1a8eb9d4d35c89e369b2f2fd2a4af5edfb>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_add_ssf<doxid-screw_8h_1a3c9494d3792e49454c7fbb3ac2d89352>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_subtract_ss<doxid-screw_8h_1aa9fa9d761704fa1153f623507352348d>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_subtract_ssf<doxid-screw_8h_1ad86f76d66b897618d6e0bce5a9edde02>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_add_sst<doxid-screw_8h_1a694609a9973a623afeefda1bc064dae2>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si1,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si2,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_add_sstf<doxid-screw_8h_1ae4371aea3644d376a82ecf329ce934fb>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si1,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si2,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_htx<doxid-screw_8h_1afe2ef0d4a1122930410c642897d98c38>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_htxf<doxid-screw_8h_1a1f13aea633ae9ca05fd505ee42438a9c>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hty<doxid-screw_8h_1a1847fad4a681462988904e25470334fc>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_htyf<doxid-screw_8h_1ab5097bed364627bfafd5d2ffc1a65c21>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_htz<doxid-screw_8h_1a6c9fd5d6bda14c8776a9039da9c68edb>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* ri,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_htzf<doxid-screw_8h_1afb53bc09a2fd5ccacb58a3d3a59e2cda>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* ri,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hrx<doxid-screw_8h_1ab5fbd0fad8e93a98f1739d487548baab>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_hrxf<doxid-screw_8h_1a52cb7ed0ef48209762827917f7628ca2>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hry<doxid-screw_8h_1a34682efe1a0b82d7922aa422b30fb337>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_hryf<doxid-screw_8h_1a6e29c843495c725418296b2c644b67e1>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hrz<doxid-screw_8h_1a12134a4aa42f6da6b546e1310075236b>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_hrzf<doxid-screw_8h_1a26a98b68c63a0fae907df9a1e8bd8fb8>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_htxinv<doxid-screw_8h_1a64e6347999ca22e50bcc471cd0c0e35e>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_htxinvf<doxid-screw_8h_1ab0f67034f70fb3b1d32b6bebd0935b7f>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_htyinv<doxid-screw_8h_1a518f1c41de8bb4b75fcfeb4835f262c2>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_htyinvf<doxid-screw_8h_1a89fe85bfca60c9b6b08952749fb44d31>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_htzinv<doxid-screw_8h_1a913fceabb404e4a65e7a8f397207a760>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_htzinvf<doxid-screw_8h_1a870420bb6b1ccd4c7ff6e343d78c5b28>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hrxinv<doxid-screw_8h_1ae03a4efc62eb052700680af0a562b1ec>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_hrxinvf<doxid-screw_8h_1aef7516989eb0ce1827d94389afb34d79>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hryinv<doxid-screw_8h_1a644b5464130512659a1231f13916e7ed>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_hryinvf<doxid-screw_8h_1aa704f202430c33b994ad397702e73b54>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_hrzinv<doxid-screw_8h_1ad8858eccb5fa00cbba06989f3d362ead>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

	void
	:ref:`ksl_hrzinvf<doxid-screw_8h_1a41cf5ba358ed78f8a40201b7074dc309>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

	void
	:ref:`ksl_cross_ss<doxid-screw_8h_1a3f90c6d736fcf3adcc7cede0de5ac98d>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_cross_ssf<doxid-screw_8h_1ac66af38b3761c8d4bf0f56fa4c248385>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_cross_sst<doxid-screw_8h_1a92a2407b4024712b0fbee78f896ed203>` (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_cross_sstf<doxid-screw_8h_1ab77558baa443db0a9ac3003b2e5fe8c0>` (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adrs<doxid-screw_8h_1a22606f0ceb8788b12eb25a20d38be7a1>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adrsinv<doxid-screw_8h_1ae2aa2e7020f68dd9b4716b9400cc754e>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adrsf<doxid-screw_8h_1a3c6d2dedcb47ca15e4dfa198f84a6a44>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adrsinvf<doxid-screw_8h_1ac1c548130b277dc68ed9c72bff498030>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adrinvs<doxid-screw_8h_1aadc61d866d74258ccc9bdfe151213ff8>` (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adrinvsf<doxid-screw_8h_1a5f1226ded1159f5695a22f944302f418>` (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adts<doxid-screw_8h_1ad608d5b26172dbcc52dbd454b664e693>` (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adtsf<doxid-screw_8h_1a3d09944886b213613b15da820f5f74ef>` (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adtinvs<doxid-screw_8h_1aff6e27f1af1f740ab4ff3319a74b3a69>` (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adtinvsf<doxid-screw_8h_1aa9f5f696af95682f42ffdef47ba0dbc6>` (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adtsinv<doxid-screw_8h_1ac01634179e19f20f6bd8c7cbc597437d>` (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adtsinvf<doxid-screw_8h_1a3dabab03e28df14d9bd91f67e6d9061f>` (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Ads<doxid-screw_8h_1a1d19786f414359ed21a6649d8be99e57>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adsinv<doxid-screw_8h_1ac9de2b0dfe4e74cf65f3238c0745a675>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adsinvf<doxid-screw_8h_1acf2c57239c0478f7b9f435aa76c04589>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adsf<doxid-screw_8h_1a14769fe5e3c6d68015c47bfebecd6b24>` (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

	void
	:ref:`ksl_product_Adinvs<doxid-screw_8h_1a66239941994450b928f4ce8fd2016f2c>` (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

	void
	:ref:`ksl_product_Adinvsf<doxid-screw_8h_1a15fa0415230d31423d5d363ccaa73d62>` (
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

	bool
	ksl_allclosei (
	    const int count,
	    const int* a1,
	    const int* a2
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

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`
	:ref:`ksl_vec3<doxid-vector_8h_1ad5d4b78eae694f6831e6a5df916a6eda>` (
	    const double x,
	    const double y,
	    const double z
	    )

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`
	:ref:`ksl_vec3f<doxid-vector_8h_1a8c1da367b7daa11d0f3ed63ae50712ce>` (
	    const float x,
	    const float y,
	    const float z
	    )

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`
	:ref:`ksl_vec3i<doxid-vector_8h_1aa432faefe6257a90d3245b9ac54fed54>` (
	    const int x,
	    const int y,
	    const int z
	    )

	:ref:`ksl_vec4i_t<doxid-unionksl__vec4i__t>`
	ksl_vec4i (
	    const int x,
	    const int y,
	    const int z,
	    const int w
	    )

	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`
	:ref:`ksl_vec4<doxid-vector_8h_1afd6bb01fca0d56d7514eae51b205c9a7>` (
	    const double x,
	    const double y,
	    const double z,
	    const double w
	    )

	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`
	:ref:`ksl_vec4f<doxid-vector_8h_1a54c592f1f7175d5a77a9ca3bd6af1181>` (
	    const float x,
	    const float y,
	    const float z,
	    const float w
	    )

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*
	:ref:`ksl_vec3_alloc<doxid-vector_8h_1a8ff66788e56f867bc2b1c592e698d12f>` (int)

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*
	:ref:`ksl_vec3f_alloc<doxid-vector_8h_1aa2c429697e1dcde474785e471b76b0f5>` (int)

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`*
	:ref:`ksl_vec3i_alloc<doxid-vector_8h_1ac65f639fbad229acffaca7139afadb48>` (int)

	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`*
	:ref:`ksl_vec4_alloc<doxid-vector_8h_1ad8219bcf00ad612fa1791efff35c0a54>` (int)

	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`*
	:ref:`ksl_vec4f_alloc<doxid-vector_8h_1a67c0ecb326dd2dd17cb2467e2c33f067>` (int)

	:ref:`ksl_vec4i_t<doxid-unionksl__vec4i__t>`*
	:ref:`ksl_vec4i_alloc<doxid-vector_8h_1a6942778c81cae89afc59b8e78381dec7>` (int)

	double
	ksl_vec3_l2norm (const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v)

	float
	ksl_vec3f_l2norm (const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v)

	double
	ksl_vec4_l2norm (const :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v)

	float
	ksl_vec4f_l2norm (const :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v)

	void
	ksl_vec3_normalize (:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v)

	void
	ksl_vec3f_normalize (:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v)

	void
	ksl_vec4_normalize (:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v)

	void
	ksl_vec4f_normalize (:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v)

	void
	ksl_vec3_normalized (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_vec3f_normalized (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_vec4_normalized (
	    const :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v,
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vo
	    )

	void
	ksl_vec4f_normalized (
	    const :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v,
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vo
	    )

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
	ksl_vec4_scale (
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v,
	    const double
	    )

	void
	ksl_vec4f_scale (
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v,
	    const float
	    )

	void
	ksl_vec3_scaled (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v,
	    const double,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

	void
	ksl_vec3f_scaled (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v,
	    const float,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

	void
	ksl_vec4_scaled (
	    const :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v,
	    const double,
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vo
	    )

	void
	ksl_vec4f_scaled (
	    const :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v,
	    const float,
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vo
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
	ksl_vec4_copy (
	    const :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vi,
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vo
	    )

	void
	ksl_vec4f_copy (
	    const :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vi,
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vo
	    )

	void
	ksl_vec3_swap (
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v1,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* v2
	    )

	void
	ksl_vec3f_swap (
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v1,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* v2
	    )

	void
	ksl_vec4_swap (
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v1,
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* v2
	    )

	void
	ksl_vec4f_swap (
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v1,
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* v2
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

	void
	ksl_vec4_inverted (
	    const :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vi,
	    :ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vo
	    )

	void
	ksl_vec4_invert (:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`* vi)

	void
	ksl_vec4f_inverted (
	    const :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vi,
	    :ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vo
	    )

	void
	ksl_vec4f_invert (:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`* vi)

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
	ksl_product_avinvf (
	    const float ki,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
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
	#define :ref:`ksl_SE3_debug<doxid-print_8h_1aa4b538500dcedc748c4aa6c693b10b49>`(f, m, ...)
	#define :ref:`ksl_SE3_print<doxid-print_8h_1a8341812ecc6045c1ad52d301e836751f>`(f, m, ...)
	#define :ref:`ksl_SE3f_debug<doxid-print_8h_1a5049da03b9f0cc1fee07384d41b71d82>`(f, m, ...)
	#define :ref:`ksl_SE3f_print<doxid-print_8h_1a25bc4d224bdd04adbaf3d31586b3c754>`(f, m, ...)
	#define :ref:`ksl_array2D_debug<doxid-print_8h_1a7a3b5c0c2b87a097489948f230c0932a>`(f, m, n, a, ...)
	#define :ref:`ksl_array2D_print<doxid-print_8h_1abbdc75045ba05ed66d03becef8b3d854>`(f, m, n, a, ...)
	#define :ref:`ksl_array_debug<doxid-print_8h_1a28197a9dd99c053d29e1bd470250ffbd>`(f, n, a, ...)
	#define :ref:`ksl_array_print<doxid-print_8h_1a712761955bd5302e081d971f072cda4e>`(f, n, a, ...)
	#define :ref:`ksl_arrayi_debug<doxid-print_8h_1ae7918065a65b86589495e5765d584ab2>`(f, n, a, ...)
	#define :ref:`ksl_arrayi_print<doxid-print_8h_1a4bb299446d942f72d05f014a43e8cef8>`(f, n, a, ...)
	#define :ref:`ksl_coscrew_debug<doxid-print_8h_1a49b77ed4e5568d676402ee85eb097539>`(f, v, ...)
	#define :ref:`ksl_coscrew_print<doxid-print_8h_1ae6f445427223d0e2d1c5fc8754d01607>`(f, v, ...)
	#define :ref:`ksl_coscrewf_debug<doxid-print_8h_1aba5a25f4159556dd2619e6152b681c47>`(f, v, ...)
	#define :ref:`ksl_coscrewf_print<doxid-print_8h_1a661e7a6a2bd86c5b4c47308b44c2d463>`(f, v, ...)
	#define :ref:`ksl_inertia_debug<doxid-print_8h_1ae2e245ebb9d399be3eaf3a8db86a208a>`(f, m, ...)
	#define :ref:`ksl_inertia_print<doxid-print_8h_1ae7c99f22b93093fe89fdd76073c32f69>`(f, m, ...)
	#define :ref:`ksl_mat3x3_debug<doxid-print_8h_1a6b1f1f1327bb35346be81d6d8a57a683>`(f, m, ...)
	#define :ref:`ksl_mat3x3_getEulerAngles<doxid-matrix_8h_1a075673d8b8724b0b149e3d2444a81d2e>`(r, angles, axisType, ...)
	#define :ref:`ksl_mat3x3_print<doxid-print_8h_1a18c6ce31ebb6566618c2c37c8880e78d>`(f, m, ...)
	#define :ref:`ksl_mat3x3f_debug<doxid-print_8h_1a724108f99723d9c533f5e7271021beb0>`(f, m, ...)
	#define :ref:`ksl_mat3x3f_getEulerAngles<doxid-matrix_8h_1a7f9d70aa654ca2ec9834920e6513e098>`(r, angles, axisType, ...)
	#define :ref:`ksl_mat3x3f_print<doxid-print_8h_1a771b950c28c042929e799a14c77ae5ce>`(f, m, ...)
	#define :ref:`ksl_mat4x4_debug<doxid-print_8h_1afe715b05556f3b8df30de17d961c7b4e>`(f, m, ...)
	#define :ref:`ksl_mat4x4_print<doxid-print_8h_1a03bac481a25734bb765ba996a0ad7e1d>`(f, m, ...)
	#define :ref:`ksl_mat4x4f_debug<doxid-print_8h_1a783d3c350c41f613316ef9640e08638c>`(f, m, ...)
	#define :ref:`ksl_mat4x4f_print<doxid-print_8h_1af5b884b620ce8e7b102e803297497629>`(f, m, ...)
	#define :ref:`ksl_print_setBoolean<doxid-print_8h_1acfd020e2a5856dbaf67fcc5dbc82a7b3>`(True, False, ...)
	#define :ref:`ksl_print_setBreakBetweenLinesInMatrix<doxid-print_8h_1acb24ebe9339505b1f9480f2004f20aba>`(val, ...)
	#define :ref:`ksl_print_setDelimiter<doxid-print_8h_1ab010c85ae8e4338222e9e8d91faac823>`(fmt, ...)
	#define :ref:`ksl_print_setInnerBrackets<doxid-print_8h_1a79251216895c5881dafd7edcd643eac6>`(left, right, ...)
	#define :ref:`ksl_print_setOuterBrackets<doxid-print_8h_1af5093b92d7af83b8bea2e590739299e4>`(left, right, ...)
	#define :ref:`ksl_print_setRealFormat<doxid-print_8h_1a4af08209f3477f54aecc407683913f18>`(fmt, ...)
	#define :ref:`ksl_print_setRowColumnMajorPrinting<doxid-print_8h_1a16bda9a363d071b0c70d55d16d898f53>`(val, ...)
	#define :ref:`ksl_quaternion_debug<doxid-print_8h_1a38c97b7f4dcb5c7fb9b9c81ebdcede4c>`(f, v, ...)
	#define :ref:`ksl_quaternion_print<doxid-print_8h_1ac508dd666c45837a5c0d16ab4a3b1cf1>`(f, v, ...)
	#define :ref:`ksl_quaternionf_debug<doxid-print_8h_1a81b9eeafd87b9e982c9d041caab8e4c0>`(f, v, ...)
	#define :ref:`ksl_quaternionf_print<doxid-print_8h_1acca71a66e0f48aa386fcd5377ce7f1d2>`(f, v, ...)
	#define :ref:`ksl_screw_debug<doxid-print_8h_1a8a08b99ccf7c7fdbc08a2cdd8962af09>`(f, v, ...)
	#define :ref:`ksl_screw_print<doxid-print_8h_1a5ef0d742cbe275d37160d54ac8f0054d>`(f, v, ...)
	#define :ref:`ksl_screwf_debug<doxid-print_8h_1a181f87a35a8e7ef0032a8be990fb8b8d>`(f, v, ...)
	#define :ref:`ksl_screwf_print<doxid-print_8h_1a5fad2258b319563e23fb14457c555d3c>`(f, v, ...)
	#define :ref:`ksl_triang_debug<doxid-print_8h_1ae40e8dd8eb231d6d673dd60944e91c0b>`(f, n, a, ...)
	#define :ref:`ksl_triang_print<doxid-print_8h_1a08e9ed87ddebcbdd9ee450be90b1f424>`(f, n, a, ...)
	#define :ref:`ksl_triangb_debug<doxid-print_8h_1a0f460fb54e7e5c54c17df6f7b8cf6384>`(f, n, a, ...)
	#define :ref:`ksl_triangb_print<doxid-print_8h_1a55d42c68196b42a9580a82b750aa3aee>`(f, n, a, ...)
	#define :ref:`ksl_triangi_debug<doxid-print_8h_1a1ebaf4f2934b344d11ac213143bd9502>`(f, n, a, ...)
	#define :ref:`ksl_triangi_print<doxid-print_8h_1a414a80b40c3bd652375f42a6f303d575>`(f, n, a, ...)
	#define :ref:`ksl_vec3_debug<doxid-print_8h_1a62c27e70109cee505d2045a82ed32f38>`(f, v, ...)
	#define :ref:`ksl_vec3_print<doxid-print_8h_1a168f87276c6b1fc784e6061b84595c72>`(f, v, ...)
	#define :ref:`ksl_vec3f_debug<doxid-print_8h_1a887a09b118189ce62ab9d2537b7e86f0>`(f, v, ...)
	#define :ref:`ksl_vec3f_print<doxid-print_8h_1a59940cf406975811638e5472b3ffee99>`(f, v, ...)

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

allow accessing mat3x3 quantities by field name or by using at / as_array operators. if using the at or as_array operators, quantities are accessed in column major order

.. _doxid-matrix_8h_1af4fc311539d1e7c3c1ce4a41f02ec525:
.. _cid-ksl_mat3x3f_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef union :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` ksl_mat3x3f_t

general 3x3 double precision matrix

allow accessing mat3x3 quantities by field name or by using at / as_array operators. if using the at or as_array operators, quantities are accessed in column major order

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

.. _doxid-print_8h_1a4fda31454cdfc95acbe4d9ac3f8c6197:
.. _cid-ksl_print_options_t-2:
.. ref-code-block:: cpp
	:class: title-code-block

	typedef struct :ref:`ksl_print_options_t<doxid-structksl__print__options__t>` ksl_print_options_t

print formatting options

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

.. _doxid-coscrew_8h_1a7e6704e2b69caf1cca667b98ef6ba386:
.. _cid-ksl_coscrew:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`
	ksl_coscrew (
	    const double m0,
	    const double m1,
	    const double m2,
	    const double m3,
	    const double m4,
	    const double m5
	    )

double precision screw constructor

.. _doxid-coscrew_8h_1a76c6e24c4466d7e3f1007af523aca93a:
.. _cid-ksl_coscrewf:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`
	ksl_coscrewf (
	    const float m0,
	    const float m1,
	    const float m2,
	    const float m3,
	    const float m4,
	    const float m5
	    )

single precision screwf constructor

.. _doxid-coscrew_8h_1afeca734953318cffdf39a23afd573825:
.. _cid-ksl_coscrew_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`*
	ksl_coscrew_alloc (int n)

Allocates n double precision coscrew quantities on the heap. Must be freed by the user.

.. _doxid-coscrew_8h_1ab3365b6c870dc61f52af92dd59a55af3:
.. _cid-ksl_coscrewf_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`*
	ksl_coscrewf_alloc (int n)

Allocate n single precision coscrew quantities on the heap. Must be freed by the user.

.. _doxid-coscrew_8h_1a822c04f16e9ae5d1d63fa4c52d358c28:
.. _cid-ksl_coscrew_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrew_copy (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Copy double precision :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` .

$\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ci

        - [in] screw to copy

    *
        - co

        - [out] input screw is copied to co

.. _doxid-coscrew_8h_1a7ceb266571f226b0199fc46bd92a666c:
.. _cid-ksl_coscrewf_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrewf_copy (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Copy single precision :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` ci to co.

$\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in] screw to copy

    *
        - co

        - [out] ci is copied to co

.. _doxid-coscrew_8h_1a9c0293f849cd72e459eb920e34a83c8c:
.. _cid-ksl_coscrew_scale:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrew_scale (
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* self,
	    const double a
	    )

Scale a double precision :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` .

$\mathbf{\underline{c}}_{i}^\* \* a \rightarrow \mathbf{\underline{c}}_i^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in] coscrew to invert

    *
        - a

        - [out] amount to scale the screw

.. _doxid-coscrew_8h_1a1290a4c68beb018bc86f49e6ae8ea78c:
.. _cid-ksl_coscrewf_scale:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrewf_scale (
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self,
	    const float a
	    )

Scale a single precision :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` .

$\mathbf{\underline{c}}_{i}^\* \* a \rightarrow \mathbf{\underline{c}}_i^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in] coscrew to invert

    *
        - a

        - [out] inverse of ci

.. _doxid-coscrew_8h_1adde0d1e7c997c2ad903446a14cdebd1c:
.. _cid-ksl_coscrew_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrew_inverted (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Returns the inverse of a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` .

$-\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ci

        - [in] coscrew to invert

    *
        - co

        - [out] inverse of ci

.. _doxid-coscrew_8h_1a16aba5a97df44e95d632fa253166c277:
.. _cid-ksl_coscrewf_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrewf_inverted (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Returns the inverse of a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` .

$-\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in] coscrew to invert

    *
        - co

        - [out] inverse of ci

.. _doxid-coscrew_8h_1ad71f0bc9f4c7baa4ed3215db8a6d181c:
.. _cid-ksl_coscrew_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrew_invert (:ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* self)

Invert (i.e. negate) a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` in place.

$-\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_i^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in/out] coscrew to invert

.. _doxid-coscrew_8h_1ac3f856a46560c8e92d68d91f3f0b0d0f:
.. _cid-ksl_coscrewf_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_coscrewf_invert (:ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* self)

Invert (i.e. negate) a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` in place.

$-\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_i^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in/out] coscrew to invert

.. _doxid-coscrew_8h_1abb248fdd9c35689ad7034b94faa372b0:
.. _cid-ksl_axpy_cc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_axpy_cc (
	    const double a,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* x,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* y
	    )

In-place add a double precision coscrew multiplied with a scalar to an existing coscrew.

$a \* \mathbf{\underline{c}}_{x}^\* + \mathbf{\underline{c}}_y^\* \rightarrow \mathbf{\underline{c}}_y^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - [in]

    *
        - x

        - [in]

    *
        - y

        - [in/out] coscrew to add

.. _doxid-coscrew_8h_1af12817c5f697e8d030363906622a9da4:
.. _cid-ksl_axpy_ccf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_axpy_ccf (
	    const float a,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* x,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* y
	    )

In-place add a single precision coscrew multiplied with a scalar to an existing coscrew.

$a \* \mathbf{\underline{c}}_{x}^\* + \mathbf{\underline{c}}_y^\* \rightarrow \mathbf{\underline{c}}_y^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - a

        - [in]

    *
        - x

        - [in]

    *
        - y

        - [in/out]

.. _doxid-coscrew_8h_1ac8637884cf89c41f96f8d2536a381140:
.. _cid-ksl_xpy_cc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_xpy_cc (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* x,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* y
	    )

In-place add a double precision coscrew to an existing coscrew. This is a variant of axpy where the scalar term a is 1.

$ \mathbf{\underline{c}}_{x}^\* + \mathbf{\underline{c}}_y^\* \rightarrow \mathbf{\underline{c}}_y^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c

        - [in/out]

    *
        - ci

        - [in] coscrew to add

.. _doxid-coscrew_8h_1a3aae63afe3e494e5478336efef92eeec:
.. _cid-ksl_xpy_ccf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_xpy_ccf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* x,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* y
	    )

In-place add a single precision coscrew to an existing coscrew. This is a variant of axpy where there the scalar term is 1.

$ \mathbf{\underline{c}}_{x}^\* + \mathbf{\underline{c}}_y^\* \rightarrow \mathbf{\underline{c}}_y^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - co

        - [in/out] sum of c1i and co

    *
        - c1i

        - [in] first coscrew to add

.. _doxid-coscrew_8h_1a26bfc464185b927b9d69eefb247a570a:
.. _cid-ksl_nxpy_cc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_nxpy_cc (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* x,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* y
	    )

In-place subtract a double precision coscrew x from an coscrew y. This is a variant of axpy where the scalar term is -1.

$ -\mathbf{\underline{c}}_{x}^\* + \mathbf{\underline{c}}_y^\* \rightarrow \mathbf{\underline{c}}_y^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in/out]

    *
        - ci

        - [in] first coscrew to subtract

.. _doxid-coscrew_8h_1aa48627036b044008b5ae78b6e7728d1b:
.. _cid-ksl_nxpy_ccf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_nxpy_ccf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* x,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* y
	    )

In-place subtract a single precision coscrew from an existing coscrew. This is a variant of axpy where the scalar term is -1.

$ -\mathbf{\underline{c}}_{x}^\* + \mathbf{\underline{c}}_y^\* \rightarrow \mathbf{\underline{c}}_y^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - self

        - [in/out]

    *
        - ci

        - [in] first coscrew to subtract

.. _doxid-coscrew_8h_1ada223e7701cf1454472c3bdd6aeb2a8c:
.. _cid-ksl_product_ca:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ca (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    const double a,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Scale a double precision coscrew.

$ \mathbf{\underline{c}}_i^\* \* a \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ci

        - [in/out] coscrew to invert

.. _doxid-coscrew_8h_1a9575e49d6dc7ddecd6c6ddd64309634a:
.. _cid-ksl_product_caf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_caf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    const float a,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Scale a single precision coscrew.

$ \mathbf{\underline{c}}_i^\* \* a \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ci

        - [in/out] coscrew to invert

.. _doxid-coscrew_8h_1a59dadd311149ae3e5e520185899695f4:
.. _cid-ksl_add_cc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_add_cc (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Compute the sum of two double precision coscrews.

$\mathbf{\underline{c}}_{1i}^\* + \mathbf{\underline{c}}_{2i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c1i

        - [in] first coscrew to add

    *
        - c1i

        - [in] second coscrew to add

    *
        - co

        - [out] sum of c1i and c2i

.. _doxid-coscrew_8h_1a9f13a22010bf04e81391b72b6e0b659c:
.. _cid-ksl_add_ccf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_add_ccf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Compute the sum of two single precision coscrews.

$\mathbf{\underline{c}}_{1i}^\* + \mathbf{\underline{c}}_{2i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c1i

        - [in] first coscrew to add

    *
        - c2i

        - [in] second coscrew to add

    *
        - co

        - [out] sum of c1i and c2i

.. _doxid-coscrew_8h_1a9789cd04fdfd6ba1bb3116e5de7bfb9b:
.. _cid-ksl_subtract_cc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_subtract_cc (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Compute the difference between two double precision coscrews.

$\mathbf{\underline{c}}_{1i}^\* - \mathbf{\underline{c}}_{2i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c1i

        - [in] first coscrew

    *
        - c2i

        - [in] second coscrew

    *
        - co

        - [out] c1i minus c2i

.. _doxid-coscrew_8h_1a232011f12579ecf2b94f0fe7dbc1ed78:
.. _cid-ksl_subtract_ccf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_subtract_ccf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Compute the difference between two double precision coscrews.

$\mathbf{\underline{c}}_{1i}^\* - \mathbf{\underline{c}}_{2i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c1i

        - [in] first coscrew

    *
        - c2i

        - [in] second coscrew

    *
        - co

        - [out] result of c1i minus c2i

.. _doxid-coscrew_8h_1ade4b35932b19f74784e1c86975e8b055:
.. _cid-ksl_cross_cc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_cross_cc (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c1i,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* c2i,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Compute the double precision coscrew cross product.

$ \mathbf{\underline{c}}_{1i}^\* \times \mathbf{\underline{c}}_{2i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c1i

        - [in] first coscrew

    *
        - c2i

        - [in] second coscrew

    *
        - co

        - [out] result of c1i x c2i

.. _doxid-coscrew_8h_1ae2bdbfdf4104c4230d33aa51ea383128:
.. _cid-ksl_cross_ccf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_cross_ccf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c1i,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* c2i,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Compute the single precision coscrew cross product.

$\mathbf{\underline{c}}_{1i}^\* \times \mathbf{\underline{c}}_{2i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - c1i

        - [in] first coscrew

    *
        - c2i

        - [in] second coscrew

    *
        - co

        - [out] result of c1i x c2i

.. _doxid-coscrew_8h_1aea01c281ea5652435836dc9374820d41:
.. _cid-ksl_product_coadtc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdtc (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Performs a double precision spatial translation of a coscrew. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of only a translation component.

$ [Ad]^\*(\underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ti

        - [in] translation vector

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a7a3ade7bd8ff468dd63f944247d667c1:
.. _cid-ksl_product_coadtcf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdtcf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Performs a single precision spatial translation of a coscrew. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of only a translation component.

$ [Ad]^\*(\underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ti

        - [in] translation vector

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a418fcdb10f1b086d46c22271430c9db3:
.. _cid-ksl_product_coadtcinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdtcinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Performs a double precision spatial translation of the inverse of a coscrew. Performs a Coadjoint transformation of the inverse of a coscrew, where CoAdjoint transformation matrix consists of only a translation component.

$ [Ad]^\*(\underline{t}_i) \* -\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ -[Ad]^\*(\underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ -\begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ti

        - [in] translation vector

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a3929622d53bb5e2de5c3f98e2d660e7f:
.. _cid-ksl_product_coadtcinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdtcinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Performs a single precision spatial translation of the inverse of a coscrew. Performs a Coadjoint transformation of the inverse of a coscrew, where CoAdjoint transformation matrix consists of only a translation component.

$ [Ad]^\*(\underline{t}_i) \* -\mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ -[Ad]^\*(\underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ -\begin{bmatrix} I & 0\\ \underline{\tilde{t}}_i & I \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ti

        - [in] translation vector

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a2849447a782870e7450ff21cdb6b0394:
.. _cid-ksl_product_coadrc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdrc (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Performs a double precision spatial rotation of a coscrew. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of only a rotation component.

$ [Ad]^\*(R_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i & 0\\ 0 & R_i \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Ri

        - [in] input rotation matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1aa2eaf64d9ad04b1ec95c78fa3cca7139:
.. _cid-ksl_product_coadrcf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdrcf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Performs a single precision spatial rotation of a coscrew. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of only a rotation component.

$ [Ad]^\*(R_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i & 0\\ 0 & R_i \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Ri

        - [in] input rotation matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1accc4e52ece31b13e54717307669846ec:
.. _cid-ksl_product_coadrinvc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdrinvc (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Performs a double precision spatial rotation of a coscrew, using the transpose of the input rotation matrix. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of only a rotation component transposed.

$ [Ad]^\*(R_i^T) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ \left([Ad]^\*(R_i) \right)^{-1} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i^T & 0\\ 0 & R_i^T \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Ri

        - [in] input rotation matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a7014f00cf6f331b6be58db7415b61ed0:
.. _cid-ksl_product_coadrinvcf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdrinvcf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Performs a single precision spatial rotation of a coscrew, using the transpose of the input rotation matrix. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of only a rotation component transposed.

$ [Ad]^\*(R_i^T) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ \left([Ad]^\*(R_i) \right)^{-1} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i^T & 0\\ 0 & R_i^T \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Ri

        - [in] input rotation matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1ac9cdfbc205413c7057fa54654db46be9:
.. _cid-ksl_product_coadc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdc (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Performs a double precision spatial transformation of a coscrew. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of a rotation and translation component.

$ [Ad]^\*(\Phi_{Di}) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ [Ad]^\*(R_i, \underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i & 0\\ \tilde{\underline{t}}_i R_i & R_i \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Ri

        - [in] input rotation matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a8be0b50f6087f6d0e4b924127c3664ce:
.. _cid-ksl_product_coadcf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdcf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Performs a single precision spatial transformation of a coscrew. Performs a Coadjoint transformation of a coscrew, where CoAdjoint transformation matrix consists of a rotation and translation component.

$ [Ad]^\*(\Phi_{Di}) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ [Ad]^\*(R_i, \underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i & 0\\ \tilde{\underline{t}}_i R_i & R_i \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Di

        - [in] input SE3 matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1ad0f1fb989507684b936e917cb35c556f:
.. _cid-ksl_product_coadinvc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdinvc (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* co
	    )

Performs the inverse single precision spatial transformation of a coscrew. Performs the inverse of a Coadjoint transformation of a coscrew, where the CoAdjoint transformation matrix consists of a rotation and translation component.

$ [Ad]^\*(\Phi_{Di}^{-1}) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ \left( [Ad]^\*(\Phi_{Di}) \right)^{-1} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ [Ad]^\*(R_i^T, -\underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i^T & 0\\ -\tilde{\underline{t}}_i R_i^T & R_i^T \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Di

        - [in] input SE3 matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-coscrew_8h_1a24f2cd5aa0326db48165973bc0c53464:
.. _cid-ksl_product_coadinvcf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_CoAdinvcf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* co
	    )

Performs the inverse single precision spatial transformation of a coscrew. Performs the inverse of a Coadjoint transformation of a coscrew, where the CoAdjoint transformation matrix consists of a rotation and translation component.

$ [Ad]^\*(\Phi_{Di}^{-1}) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ \left( [Ad]^\*(\Phi_{Di}) \right)^{-1} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$ [Ad]^\*(R_i^T, -\underline{t}_i) \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$

$\ \begin{bmatrix} R_i^T & 0\\ -\tilde{\underline{t}}_i R_i^T & R_i^T \end{bmatrix} \mathbf{\underline{c}}_{i}^\* \rightarrow \mathbf{\underline{c}}_o^\*$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - Di

        - [in] input SE3 matrix

    *
        - ci

        - [in] input coscrew

    *
        - co

        - [out] output coscrew

.. _doxid-inertia_8h_1ae205178752af78031aa294a2afb2abeb:
.. _cid-ksl_inertia:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`
	ksl_inertia (
	    const double m,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t,
	    const double Ixx,
	    const double Iyy,
	    const double Izz,
	    const double Ixy,
	    const double Iyz,
	    const double Izx
	    )

double precision spatial inertia matrix constructor



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - m

        - [in] mass

    *
        - t

        - [in] vector from reference frame to body centroid

    *
        - Ixx

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Iyy

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Izz

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Ixy

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Iyz

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Izx

        - [in] centroidal inertia term, expressed in reference frame coordinates

.. _doxid-inertia_8h_1ac5464502b987b6b23ac37d3b354e6534:
.. _cid-ksl_inertiaf:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`
	ksl_inertiaf (
	    const float m,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t,
	    const float Ixx,
	    const float Iyy,
	    const float Izz,
	    const float Ixy,
	    const float Iyz,
	    const float Izx
	    )

single precision spatial inertia matrix constructor



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - m

        - [in] mass

    *
        - t

        - [in] vector from reference frame to body centroid

    *
        - Ixx

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Iyy

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Izz

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Ixy

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Iyz

        - [in] centroidal inertia term, expressed in reference frame coordinates

    *
        - Izx

        - [in] centroidal inertia term, expressed in reference frame coordinates

.. _doxid-inertia_8h_1a3bb757d9e15c170aeb46a78f8fea71e7:
.. _cid-ksl_inertia_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`*
	ksl_inertia_alloc (int n)

allocate n :ref:`ksl_inertia_t <doxid-unionksl__inertia__t>` datastructures on the heap

.. _doxid-inertia_8h_1a4636dcf376b3d6cc02ccd5c9fa97a599:
.. _cid-ksl_inertiaf_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`*
	ksl_inertiaf_alloc (int n)

allocate n :ref:`ksl_inertiaf_t <doxid-unionksl__inertiaf__t>` datastructures on the heap

.. _doxid-inertia_8h_1a4a387d0c872abcabf269273ba58db901:
.. _cid-ksl_inertia_rotated:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_rotated (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

rotate a double precision centroidal inertia matrix

I_ff = CoAd(D(R_{fc})) \* Icc \* Ad(D(R_{fc}^{-1}))

.. _doxid-inertia_8h_1a1a1e3f03ccf343e0bbae6cf5b5057bf9:
.. _cid-ksl_inertiaf_rotated:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_rotated (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

rotate a single precision centroidal inertia matrix

$ I_{ff} = CoAd(D(R_{fc})) \* I_{cc} \* Ad(D(R_{fc}^{-1})) $

.. _doxid-inertia_8h_1a5143ef0a4aa1f7a701d28388aa8cf1e1:
.. _cid-ksl_inertia_rotate:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_rotate (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r
	    )

rotate a double precision centroidal inertia matrix in place

$ I_{ff} = CoAd(D(R_{fc})) \* I_{cc} \* Ad(D(R_{fc}^{-1})) $

.. _doxid-inertia_8h_1a095683dadc83becbf6160d84888bdbd8:
.. _cid-ksl_inertiaf_rotate:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_rotate (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r
	    )

rotate a single precision centroidal inertia matrix in place

$ I_{ff} = CoAd(D(R_{fc})) \* I_{cc} \* Ad(D(R_{fc}^{-1})) $

.. _doxid-inertia_8h_1a0ffd6ef04f8f7abb2901d45fd22daf63:
.. _cid-ksl_inertia_translated:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_translated (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* r,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

translate a double precision centroidal inertia matrix

$ I_ff = CoAd(D(t_{fc})) \* Icc \* Ad(D(t_{fc}^{-1})) $

.. _doxid-inertia_8h_1a073ce8555bd68566833b2b7ef95e181e:
.. _cid-ksl_inertiaf_translated:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_translated (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* r,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

translate a single precision centroidal inertia matrix

$ I_{ff} = CoAd(D(t_{fc})) \* I_{cc} \* Ad(D(t_{fc}^{-1})) $

.. _doxid-inertia_8h_1a05c6d53f909791b8796bbb4fe909a789:
.. _cid-ksl_inertia_translate:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_translate (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* r
	    )

translate a double precision centroidal inertia matrix in place

$ I_ff = CoAd(D(t_{fc})) \* Icc \* Ad(D(t_{fc}^{-1})) $

.. _doxid-inertia_8h_1a896b52736acad0b43b06d61fac55b99f:
.. _cid-ksl_inertiaf_translate:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_translate (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* r
	    )

translate a single precision centroidal inertia matrix in place

$ I_{ff} = CoAd(D(t_{fc})) \* I_{cc} \* Ad(D(t_{fc}^{-1})) $

.. _doxid-inertia_8h_1a2e0ddd09114d6e78d0395419dac7d51d:
.. _cid-ksl_inertia_transformed:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_transformed (
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_o
	    )

spatial transform a double precision centroidal inertia matrix

$ I_ff = CoAd(D_{fc}) \* Icc \* Ad(D_{fc}^{-1}) $

.. _doxid-inertia_8h_1adcaf2a48154f2ab93b1c88fb0a655992:
.. _cid-ksl_inertiaf_transformed:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_transformed (
	    const :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_o
	    )

spatial transform a single precision centroidal inertia matrix

$ I_{ff} = CoAd(D_{fc}) \* Icc \* Ad(D_{fc}^{-1}) $

.. _doxid-inertia_8h_1ad0490956ce03ec5eb1de20e11af52505:
.. _cid-ksl_inertia_transform:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_transform (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d
	    )

spatial transform a double precision centroidal inertia matrix in place

$ I_ff = CoAd(D_{fc}) \* Icc \* Ad(D_{fc}^{-1}) $

.. _doxid-inertia_8h_1a9e1b20d519877020a4fd52a447ba0d9c:
.. _cid-ksl_inertiaf_transform:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_transform (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d
	    )

spatial transform a single precision centroidal inertia matrix in place

$ I_{ff} = CoAd(D_{fc}) \* Icc \* Ad(D_{fc}^{-1}) $

.. _doxid-inertia_8h_1aaa8803a3a2c64f1c85035bb525c1db63:
.. _cid-ksl_inertia_merge:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_merge (
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_i,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t_ic_i,
	    :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* inertia_j,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t_jc_j,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D_ij
	    )

merge double precision child inertia (j) with parent inertia (i)



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - parent

        - inertia [in/out] parent inertia to be merged

    *
        - t_ic_i

        - [in/out] vector from parent body reference frame i to body center of mass frame c, expressed in body frame i

    *
        - child

        - inertia [in]

    *
        - t_jc_j

        - [in] vector from child body reference frame j to body center of mass frame c, expressed in body frame j

    *
        - D_ij

        - [in] transformation from parent reference frame i to child reference frame j

.. _doxid-inertia_8h_1ad2a5726ed9a42f28903084ae99eac1ca:
.. _cid-ksl_inertiaf_merge:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertiaf_merge (
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_i,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t_ic_i,
	    :ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`* inertia_j,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t_jc_j,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D_ij
	    )

merge single precision child inertia (j) with parent inertia (i)



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - parent

        - inertia [in/out] parent inertia to be merged

    *
        - t_ic_i

        - [in/out] vector from parent body reference frame i to body center of mass frame c, expressed in body frame i

    *
        - child

        - inertia [in]

    *
        - t_jc_j

        - [in] vector from child body reference frame j to body center of mass frame c, expressed in body frame j

    *
        - D_ij

        - [in] transformation from parent reference frame i to child reference frame j

.. _doxid-inertia_8h_1a4d826f10adde0189c80e4018a4114ab2:
.. _cid-ksl_inertia_factor:
.. ref-code-block:: cpp
	:class: title-code-block

	int
	ksl_inertia_factor (:ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`*)

factor double precision inertia matrix

Todo finish this

inertia matrix is overwritten with its factors

4 cases: rank 2+, full rank, positive definite, or rank 2, positive semidefinite rank 1, positive semidefinite rank 0, do nothing



.. rubric:: Returns:

rank of inertia matrix

.. _doxid-inertia_8h_1a9a7a767bc2e0caf961f4fb1689fbfc11:
.. _cid-ksl_inertiaf_factor:
.. ref-code-block:: cpp
	:class: title-code-block

	int
	ksl_inertiaf_factor (:ref:`ksl_inertiaf_t<doxid-unionksl__inertiaf__t>`*)

factor single precision inertia matrix

Todo finish this

inertia matrix is overwritten with its factors

4 cases: rank 2+, full rank, positive definite, or rank 2, positive semidefinite rank 1, positive semidefinite rank 0, do nothing



.. rubric:: Returns:

rank of inertia matrix

.. _doxid-linalg_8h_1a50a42897bbde4b0b692f73c9340c846e:
.. _cid-ksl_linalg_lu_setcmatrix_rmo:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_linalg_lu_setCMatrix_rmo (
	    int rowDim,
	    int colDim,
	    int rank,
	    double* A
	    )

compute Row Major Order C matrix

This block overwrites LR with LR\*inverse(Lr) If rank==1, the Lr matrix is a 1 by 1 identity matrix, so there is nothing to do here. This loop computes A[rank:rowDim-1][0:rank-1]=LR\*inverse(Lr) where LR is stored in A[rank:rowDim-1][0:rank-1] and Lr is stored in A[0:rank-1][0:rank-1]. j is the column number in LR. It ends at 1 because the diagonal entry in row 0 of Lr is 1. i is the row number in LR. k is the column number in Lr



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - rowDim

        - [in] row dimension of matrix A.

    *
        - colDim

        - [in] column dimension of matrix A.

    *
        - rank

        - [in] rank of matrix A.

    *
        - \*A

        - [in/out] matrix with dimensions A[0:rowDim-1][0:colDim-1]:

.. _doxid-linalg_8h_1a0f4d5fe5074266d025a4c900ba95ab34:
.. _cid-ksl_linalg_lu_setcmatrix_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_linalg_lu_setCMatrix_cmo (
	    int rowDim,
	    int colDim,
	    int rank,
	    double* A
	    )

compute Column Major Order C matrix

This block overwrites LR with LR\*inverse(Lr) If rank==1, the Lr matrix is a 1 by 1 identity matrix, so there is nothing to do here. This loop computes A[rank:rowDim-1][0:rank-1]=LR\*inverse(Lr) where LR is stored in A[rank:rowDim-1][0:rank-1] and Lr is stored in A[0:rank-1][0:rank-1]. j is the column number in LR. It ends at 1 because the diagonal entry in row 0 of Lr is 1. i is the row number in LR. k is the column number in Lr



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - rowDim

        - [in] row dimension of matrix A.

    *
        - colDim

        - [in] column dimension of matrix A.

    *
        - rank

        - [in] rank of matrix A.

    *
        - \*A

        - [in/out] matrix with dimensions A[0:rowDim-1][0:colDim-1]:

.. _doxid-matrix_8h_1af666448ab4ee33d60df0f1a06bc2200f:
.. _cid-ksl_se3:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	ksl_SE3 (
	    const double m00,
	    const double m01,
	    const double m02,
	    const double m03,
	    const double m10,
	    const double m11,
	    const double m12,
	    const double m13,
	    const double m20,
	    const double m21,
	    const double m22,
	    const double m23
	    )

:ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` constructor.

Note that in the constructor, fields are specified in row major order. Internally, :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructures are stored in column major order.

.. _doxid-matrix_8h_1a36fbb29343e99dba5df354e77e757f85:
.. _cid-ksl_se3_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	ksl_SE3_cmo (
	    const double m00,
	    const double m10,
	    const double m20,
	    const double m01,
	    const double m11,
	    const double m21,
	    const double m02,
	    const double m12,
	    const double m22,
	    const double m03,
	    const double m13,
	    const double m23
	    )

alternative :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` constructor.

In this alternate constructor, fields are specified in column major order to match the internal layout of :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructures.

.. _doxid-matrix_8h_1a897f5a11eaa0b29c6f8c4d1b6ae49e62:
.. _cid-ksl_se3_fromrt:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`
	ksl_SE3_fromRt (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t
	    )

alternative :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` constructor that allows creating a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure from a rotation matrix and translation vector.

.. _doxid-matrix_8h_1a50d5e14c3f8018c3af19d871a1c9bb77:
.. _cid-ksl_se3f:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	ksl_SE3f (
	    const float m00,
	    const float m01,
	    const float m02,
	    const float m03,
	    const float m10,
	    const float m11,
	    const float m12,
	    const float m13,
	    const float m20,
	    const float m21,
	    const float m22,
	    const float m23
	    )

:ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` constructor.

Note that in the constructor, fields are specified in row major order. Internally, :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructures are stored in column major order.

.. _doxid-matrix_8h_1a99ac89949a852c61a95469d0bf4d5c78:
.. _cid-ksl_se3f_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	ksl_SE3f_cmo (
	    const float m00,
	    const float m10,
	    const float m20,
	    const float m01,
	    const float m11,
	    const float m21,
	    const float m02,
	    const float m12,
	    const float m22,
	    const float m03,
	    const float m13,
	    const float m23
	    )

alternative :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` constructor.

In this alternate constructor, fields are specified in column major order to match the internal layout of :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructures.

.. _doxid-matrix_8h_1a79a05080dd8d7e2209b88407709b8291:
.. _cid-ksl_se3f_fromrt:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`
	ksl_SE3f_fromRt (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` R,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t
	    )

alternative :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` constructor that allows creating a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure from a rotation matrix and translation vector.

.. _doxid-matrix_8h_1a0e09e8029123d8a95841902e7219a38f:
.. _cid-ksl_mat3x3:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`
	ksl_mat3x3 (
	    const double m00,
	    const double m01,
	    const double m02,
	    const double m10,
	    const double m11,
	    const double m12,
	    const double m20,
	    const double m21,
	    const double m22
	    )

:ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` constructor.

Note that in the constructor, fields are specified in row major order. Internally, :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructures are stored in column major order.

.. _doxid-matrix_8h_1ab01f7b905575b766ec35f40f429c7959:
.. _cid-ksl_mat3x3_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`
	ksl_mat3x3_cmo (
	    const double m00,
	    const double m10,
	    const double m20,
	    const double m01,
	    const double m11,
	    const double m21,
	    const double m02,
	    const double m12,
	    const double m22
	    )

alternative :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` constructor.

In this alternate constructor, fields are specified in column major order to match the internal layout of :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructures.

.. _doxid-matrix_8h_1a80ce314c95c171740b1b4feac8d8bfd5:
.. _cid-ksl_mat3x3f:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`
	ksl_mat3x3f (
	    const float m00,
	    const float m01,
	    const float m02,
	    const float m10,
	    const float m11,
	    const float m12,
	    const float m20,
	    const float m21,
	    const float m22
	    )

:ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` constructor.

Note that in the constructor, fields are specified in row major order. Internally, :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` datastructures are stored in column major order.

.. _doxid-matrix_8h_1a6ae8fa1bac40407770007cee2d0fe716:
.. _cid-ksl_mat3x3f_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`
	ksl_mat3x3f_cmo (
	    const float m00,
	    const float m10,
	    const float m20,
	    const float m01,
	    const float m11,
	    const float m21,
	    const float m02,
	    const float m12,
	    const float m22
	    )

alternative :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` constructor.

In this alternate constructor, fields are specified in column major order to match the internal layout of :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` datastructures.

.. _doxid-matrix_8h_1a31fe657a2f227b1b39b165036a804af7:
.. _cid-ksl_mat4x4:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	ksl_mat4x4 (
	    const double m00,
	    const double m01,
	    const double m02,
	    const double m03,
	    const double m10,
	    const double m11,
	    const double m12,
	    const double m13,
	    const double m20,
	    const double m21,
	    const double m22,
	    const double m23,
	    const double m30,
	    const double m31,
	    const double m32,
	    const double m33
	    )

:ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` constructor.

Note that in the constructor, fields are specified in row major order. Internally, :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructures are stored in column major order.

.. _doxid-matrix_8h_1ab7402f404bfeab3b78df60d9cebc4c91:
.. _cid-ksl_mat4x4_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	ksl_mat4x4_cmo (
	    const double m00,
	    const double m10,
	    const double m20,
	    const double m30,
	    const double m01,
	    const double m11,
	    const double m21,
	    const double m31,
	    const double m02,
	    const double m12,
	    const double m22,
	    const double m32,
	    const double m03,
	    const double m13,
	    const double m23,
	    const double m33
	    )

alternative :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` constructor.

In this alternate constructor, fields are specified in column major order to match the internal layout of :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructures.

.. _doxid-matrix_8h_1ab8e242f75d2051b81d34f595dc7b264d:
.. _cid-ksl_mat4x4_fromse3:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	ksl_mat4x4_fromSE3 (const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>` D)

alternative :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` constructor that allows creating a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructure from a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure.

.. _doxid-matrix_8h_1a333f3c1c1c0e98361dfcf5be39615a76:
.. _cid-ksl_mat4x4_fromrt:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`
	ksl_mat4x4_fromRt (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>` R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>` t
	    )

alternative :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` constructor that allows creating a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructure from :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` and :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` datastructures.

.. _doxid-matrix_8h_1afbec2c12728678a3246ec2daa619a5bb:
.. _cid-ksl_mat4x4f:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	ksl_mat4x4f (
	    const float m00,
	    const float m01,
	    const float m02,
	    const float m03,
	    const float m10,
	    const float m11,
	    const float m12,
	    const float m13,
	    const float m20,
	    const float m21,
	    const float m22,
	    const float m23,
	    const float m30,
	    const float m31,
	    const float m32,
	    const float m33
	    )

:ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` constructor.

Note that in the constructor, fields are specified in row major order. Internally, :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructures are stored in column major order.

.. _doxid-matrix_8h_1a647ff06db64c2bd395833206bdb2a28f:
.. _cid-ksl_mat4x4f_cmo:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	ksl_mat4x4f_cmo (
	    const float m00,
	    const float m10,
	    const float m20,
	    const float m30,
	    const float m01,
	    const float m11,
	    const float m21,
	    const float m31,
	    const float m02,
	    const float m12,
	    const float m22,
	    const float m32,
	    const float m03,
	    const float m13,
	    const float m23,
	    const float m33
	    )

alternative :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` constructor.

In this alternate constructor, fields are specified in column major order to match the internal layout of :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructures.

.. _doxid-matrix_8h_1a49718c56c37ca9853352797d58011334:
.. _cid-ksl_mat4x4f_fromse3f:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	ksl_mat4x4f_fromSE3f (const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>` D)

alternative :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` constructor that allows creating a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructure from a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructure.

.. _doxid-matrix_8h_1a7c1f0a47c2f163c5a82f9b1c2dde1fa0:
.. _cid-ksl_mat4x4f_fromrt:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`
	ksl_mat4x4f_fromRt (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>` R,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>` t
	    )

alternative :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` constructor that allows creating a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructure from :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` and :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` datastructures.

.. _doxid-matrix_8h_1afab63dbe2c5fc22414b3640121c2f1f6:
.. _cid-ksl_se3_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`*
	ksl_SE3_alloc (int n)

allocates n :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructures on the heap. Must be freed by the user.

.. _doxid-matrix_8h_1a396ee8308a34a141b90808ab29ec77d2:
.. _cid-ksl_se3f_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`*
	ksl_SE3f_alloc (int n)

allocates n :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructures on the heap. Must be freed by the user.

.. _doxid-matrix_8h_1adb10d5d179d7efa909f625e149d06dc2:
.. _cid-ksl_mat3x3_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*
	ksl_mat3x3_alloc (int n)

allocates n :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructures on the heap. Must be freed by the user.

.. _doxid-matrix_8h_1ab67edb3d44f67460dbe370cb00e47d6a:
.. _cid-ksl_mat3x3f_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*
	ksl_mat3x3f_alloc (int n)

allocates n :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` datastructures on the heap. Must be freed by the user.

.. _doxid-matrix_8h_1a95acc179f532a4e27d0e86c8cd73b61a:
.. _cid-ksl_mat4x4_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`*
	ksl_mat4x4_alloc (int n)

allocates n :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructures on the heap. Must be freed by the user.

.. _doxid-matrix_8h_1a23bca8091b743f378484b049ea1cfeb0:
.. _cid-ksl_mat4x4f_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`*
	ksl_mat4x4f_alloc (int n)

allocates n :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructures on the heap. Must be freed by the user.

.. _doxid-matrix_8h_1abe0d938eae89c1165e49792df6320f5c:
.. _cid-ksl_se3_tomat4x4:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_toMat4x4 (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* m
	    )

convert a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure to a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructure



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - d

        - [in] input SE3 datastructure

    *
        - m

        - [out] output mat4x4 matrix

.. _doxid-matrix_8h_1ab752ddf0d405c49c8217cfca6aeab93c:
.. _cid-ksl_se3f_tomat4x4f:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_toMat4x4f (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d,
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* m
	    )

convert a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructure to a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructure



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - d

        - [in] input SE3f datastructure

    *
        - m

        - [out] output mat4x4f matrix

.. _doxid-matrix_8h_1ace3abb7ded8d1a7a3068ab36faf23fa6:
.. _cid-ksl_se3_tomat4x4f:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_toMat4x4f (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d,
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* m
	    )

convert a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure to a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructure



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - d

        - [in] input SE3 datastructure

    *
        - m

        - [out] output mat4x4f matrix

.. _doxid-matrix_8h_1a9df9a1b57722f5dadc0f342a0b37c7a5:
.. _cid-ksl_dc:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_dc (
	    const double thetai,
	    double dc [2]
	    )

compute double precision direction cosines from an angle specified in radians



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - thetai

        - [in] input angle

    *
        - dc

        - [out] direction cosines, with sine stored in dc[0] and cosine is stored in dc[1]

.. _doxid-matrix_8h_1a471044a6f1f405d9518e8ef9108aa978:
.. _cid-ksl_dcf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_dcf (
	    const float thetai,
	    float dc [2]
	    )

compute single precision direction cosines from an angle specified in radians



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - thetai

        - [in] input angle

    *
        - dc

        - [out] direction cosines, with sine stored in dc[0] and cosine is stored in dc[1]

.. _doxid-matrix_8h_1a1e586c05382ebb177e18490fba4f738c:
.. _cid-ksl_se3_setidentity:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_setIdentity (:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* d)

TODO document this function.

.. _doxid-matrix_8h_1add2f0dbc6d29b0b1695100a262d8ca69:
.. _cid-ksl_se3f_setidentity:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_setIdentity (:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* d)

TODO document this function.

.. _doxid-matrix_8h_1ab58fb659ed34589b759a9bff7257f9c0:
.. _cid-ksl_mat3x3_setidentity:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_setIdentity (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r)

TODO document this function.

.. _doxid-matrix_8h_1a81ad7fbd8db8e8464cf7a96c8d87df09:
.. _cid-ksl_mat3x3f_setidentity:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_setIdentity (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r)

TODO document this function.

.. _doxid-matrix_8h_1a214b4ee953af0437c415341ac20ba7c9:
.. _cid-ksl_mat3x3_set:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_set (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const int row,
	    const int column,
	    const double value
	    )

TODO document this function.

.. _doxid-matrix_8h_1a7e4178be19e7ab6820de2aed88a11f08:
.. _cid-ksl_mat4x4_set:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat4x4_set (
	    :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* R,
	    const int row,
	    const int column,
	    const double value
	    )

TODO document this function.

.. _doxid-matrix_8h_1ae4000f58b12ee4202a1851aebbcb4a3d:
.. _cid-ksl_se3_set:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_set (
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    const int row,
	    const int column,
	    const double value
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa263ec13c47bf19dfcb646fb3ac8e40d:
.. _cid-ksl_se3f_set:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_set (
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    const int row,
	    const int column,
	    const float value
	    )

TODO document this function.

.. _doxid-matrix_8h_1a2f0629a91c545f60a49380a74ce1bf46:
.. _cid-ksl_mat3x3_setfromvectors:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_setFromVectors (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* x,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* y,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* z
	    )

TODO document this function.

.. _doxid-matrix_8h_1a340c64a953a994d665382361a29229f0:
.. _cid-ksl_mat3x3f_setfromvectors:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_setFromVectors (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* x,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* y,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* z
	    )

TODO document this function.

.. _doxid-matrix_8h_1a826c58e7955ed694952468b334e42d79:
.. _cid-ksl_mat3x3f_set:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_set (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    int row,
	    int column,
	    float value
	    )

TODO document this function.

.. _doxid-matrix_8h_1aca485e889183d9468d741f5a1f347ed4:
.. _cid-ksl_mat4x4f_set:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat4x4f_set (
	    :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* D,
	    int row,
	    int column,
	    float value
	    )

TODO document this function.

.. _doxid-matrix_8h_1a1e0dc7d0fc1151b7a90d1b2b25cf7cbc:
.. _cid-ksl_mat4x4_setidentity:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat4x4_setIdentity (:ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* M)

TODO document this function.

.. _doxid-matrix_8h_1afba7a831dd92d569b81b9a0cdcefda83:
.. _cid-ksl_mat4x4f_setidentity:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat4x4f_setIdentity (:ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* M)

TODO document this function.

.. _doxid-matrix_8h_1abd65fe3a5e53ee802e2dababa95c3dc4:
.. _cid-ksl_se3_get:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_SE3_get (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    const int row,
	    const int column
	    )

TODO document this function.

.. _doxid-matrix_8h_1a83192ca3ace3ddb96906cf0ec071cc86:
.. _cid-ksl_mat3x3_get:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_mat3x3_get (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R,
	    const int row,
	    const int column
	    )

TODO document this function.

.. _doxid-matrix_8h_1a7e9dfa7888842a24a24805cebef9459e:
.. _cid-ksl_mat3x3f_get:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_mat3x3f_get (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R,
	    const int row,
	    const int column
	    )

TODO document this function.

.. _doxid-matrix_8h_1ac1a8a1a5bab85a4c524449e00e5e00e1:
.. _cid-ksl_se3f_get:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_SE3f_get (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    const int row,
	    const int column
	    )

TODO document this function.

.. _doxid-matrix_8h_1a8154daa30091f68b1ffb62e2a3cb70a1:
.. _cid-ksl_se3_gettranslation:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_getTranslation (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t
	    )

TODO document this function.

.. _doxid-matrix_8h_1a6c06836476402348d2fd554a5db26050:
.. _cid-ksl_se3f_gettranslation:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_getTranslation (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* t
	    )

TODO document this function.

.. _doxid-matrix_8h_1a659e01255e0bc4624033464e2e7182ca:
.. _cid-ksl_mat3x3_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_copy (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a0008a609192b6e2e9019d3634b15f6ad:
.. _cid-ksl_mat3x3f_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_copy (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a6223f5408884301ff82ee0c66fcf1ed2:
.. _cid-ksl_mat3x3_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	int
	ksl_mat3x3_invert (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R)

TODO document this function.

.. _doxid-matrix_8h_1a57f7021c15401bdcdc84a63eb3ccb572:
.. _cid-ksl_mat3x3f_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	int
	ksl_mat3x3f_invert (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R)

TODO document this function.

.. _doxid-matrix_8h_1a621d2689e4aa351e111b29c9b1140819:
.. _cid-ksl_mat3x3_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	int
	ksl_mat3x3_inverted (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a3f8fbfc673692d574540a3062c1a0c57:
.. _cid-ksl_mat3x3f_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	int
	ksl_mat3x3f_inverted (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a264c29f922f7813d256773dcc33b3138:
.. _cid-ksl_mat3x3_transpose:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_transpose (:ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* R)

TODO document this function.

.. _doxid-matrix_8h_1aa6d90d88f07f34c037e3f846b5de8271:
.. _cid-ksl_mat3x3f_transpose:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_transpose (:ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* R)

TODO document this function.

.. _doxid-matrix_8h_1a4fa0f7ec6a937a375afdb9865574fecc:
.. _cid-ksl_mat3x3_transposed:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_transposed (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa5574ade523fa581161cfc09b5204a05:
.. _cid-ksl_mat3x3f_transposed:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_transposed (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1aca804b2c785d9f036446df45beababae:
.. _cid-ksl_se3_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_invert (:ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D)

TODO document this function.

.. _doxid-matrix_8h_1ac05052c4b6660087dc45c399a1bf498d:
.. _cid-ksl_se3f_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_invert (:ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D)

TODO document this function.

.. _doxid-matrix_8h_1a1bb0f88b0a2aa12c88364e10817a6374:
.. _cid-ksl_se3_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_inverted (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a883d826184c26412ceddfab0f5bc97a4:
.. _cid-ksl_se3f_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_inverted (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1ad872da8f3834ab436e0388de6134fd2f:
.. _cid-ksl_se3_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3_copy (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a182b96d3aaed5e6ba17eb15748dd7a1a:
.. _cid-ksl_se3f_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_SE3f_copy (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a99c973220c97d334acefb30e0706ed9b:
.. _cid-ksl_mat3x3_geteulerangleswithreference:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_getEulerAnglesWithReference (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    const ksl_axis_enum_t axisType,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* angles,
	    ...
	    )

TODO document this function.

TODO document this function.

This function decomposes a general direction cosine matrix into three primitive direction cosine matrices, whose axes are determined by the integers passed in through axisSequence. The direction cosine matrix is passed in through Ri, and the three computed angles are updated and returned in angle. The previous values assigned to angle are passed in to RtoA in angle. RtoA calls catan2, which uses the values stored in angle to maintain continuity if at all possible. This function does not check for bad axis indices. These checks could be added but would reduce efficiency. For actual reporting purposes, especially when a large number of user output requests are to be processed.

.. _doxid-matrix_8h_1a75ed791c7dc1d6a6cbb0319e4e2b493a:
.. _cid-ksl_mat3x3f_geteulerangleswithreference:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_getEulerAnglesWithReference (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    const ksl_axis_enum_t axisType,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* angles,
	    ...
	    )

TODO document this function.

TODO document this function.

This function decomposes a general direction cosine matrix into three primitive direction cosine matrices, whose axes are determined by the integers passed in through axisSequence. The direction cosine matrix is passed in through Ri, and the three computed angles are updated and returned in angle. The previous values assigned to angle are passed in to RtoA in angle. RtoA calls catan2, which uses the values stored in angle to maintain continuity if at all possible. This function does not check for bad axis indices. These checks could be added but would reduce efficiency. For actual reporting purposes, especially when a large number of user output requests are to be processed.

.. _doxid-matrix_8h_1a1d998186da1242f36e0d3c1b26073239:
.. _cid-ksl_mat3x3_setfromeulerangles:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_setFromEulerAngles (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r,
	    const ksl_axis_enum_t axisType,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* angles
	    )

TODO document this function.

TODO document this function.

This function takes three Euler angles in one of twelve rotation orders and outputs a direction cosine matrix. The axis sequence is input through axis. Rotations about successive axes x=0, y=1, and z=2 are as follows: xyx = 010; xyz = 012; xzx = 020; xzy = 021 yxy = 101; yxz = 102; yzx = 120; yzy = 121 zxy = 201; zxz = 202; zyx = 210; zyz = 212

.. code-block:: none

    |1      |       | c     s|       |c -s   |

Rx = | c -s| Ry = | 1 | Rz = |s c | | s c| |-s c| | 1|

.. _doxid-matrix_8h_1a39aacd9b358f91bcf9ca414892f5d0fc:
.. _cid-ksl_mat3x3f_setfromeulerangles:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_setFromEulerAngles (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r,
	    const ksl_axis_enum_t axisType,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* angles
	    )

TODO document this function.

TODO document this function.

This function takes three Euler angles in one of twelve rotation orders and outputs a direction cosine matrix. The axis sequence is input through axis. Rotations about successive axes x=0, y=1, and z=2 are as follows: xyx = 010; xyz = 012; xzx = 020; xzy = 021 yxy = 101; yxz = 102; yzx = 120; yzy = 121 zxy = 201; zxz = 202; zyx = 210; zyz = 212

.. code-block:: none

    |1      |       | c     s|       |c -s   |

Rx = | c -s| Ry = | 1 | Rz = |s c | | s c| |-s c| | 1|

.. _doxid-matrix_8h_1a21b4e9dad800701badf4a4ae20e9e888:
.. _cid-ksl_mat3x3_getaxisangle:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_getAxisAngle (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*,
	    double*
	    )

TODO document this function.

.. _doxid-matrix_8h_1a305b61035160d778913d6512475f469f:
.. _cid-ksl_mat3x3_setfromaxisangle:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3_setFromAxisAngle (
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`*,
	    const double
	    )

TODO document this function.

.. _doxid-matrix_8h_1af9e7adb94891fcb280e68a475e049000:
.. _cid-ksl_mat3x3f_getaxisangle:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_getAxisAngle (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*,
	    float*
	    )

TODO document this function.

.. _doxid-matrix_8h_1a909d6e045fbf9be40b47dcca564d18de:
.. _cid-ksl_mat3x3f_setfromaxisangle:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat3x3f_setFromAxisAngle (
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`*,
	    const float
	    )

TODO document this function.

.. _doxid-matrix_8h_1a655d343e8889959a198bd3055c8c0d7c:
.. _cid-ksl_mat4x4_gettranslation:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat4x4_getTranslation (
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* Mi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* to
	    )

TODO document this function.

.. _doxid-matrix_8h_1a2d6b59053e391cf62311fcb6bf71081d:
.. _cid-ksl_mat4x4f_gettranslation:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_mat4x4f_getTranslation (
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* Mi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* to
	    )

TODO document this function.

.. _doxid-matrix_8h_1ab9d90e415397b467f5fbf24d63593913:
.. _cid-ksl_mat4x4_get:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_mat4x4_get (
	    const :ref:`ksl_mat4x4_t<doxid-unionksl__mat4x4__t>`* Mi,
	    const int row,
	    const int column
	    )

TODO document this function.

.. _doxid-matrix_8h_1aaacb3f73b5db33f0259007ea185d6a22:
.. _cid-ksl_mat4x4f_get:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_mat4x4f_get (
	    const :ref:`ksl_mat4x4f_t<doxid-unionksl__mat4x4f__t>`* Mi,
	    const int row,
	    const int column
	    )

TODO document this function.

.. _doxid-matrix_8h_1a9c6c8a3db26680b4aa525c5253a950ee:
.. _cid-ksl_mat3x3_determinant:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_mat3x3_determinant (const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`*)

TODO document this function.

.. _doxid-matrix_8h_1a19d646584d71bdbf25ec817c3bb10468:
.. _cid-ksl_mat3x3f_determinant:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_mat3x3f_determinant (const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`*)

TODO document this function.

.. _doxid-matrix_8h_1a403d3115123b4f76a6f27ec5ca7ce274:
.. _cid-ksl_product_drv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1aecf5aac9412aa19ae834d319ebd98ea5:
.. _cid-ksl_product_drvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a5b7eee293303e16c8231e8afefcbd264:
.. _cid-ksl_product_drvinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1aafcb94ac1cdfccb9971afbe83469ee48:
.. _cid-ksl_product_drvinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a6f03fffadeea016f79b189a676ef6590:
.. _cid-ksl_product_drinvv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drinvv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa4c9340e1679402e966641529aef2dd5:
.. _cid-ksl_product_drinvvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drinvvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a512dbc30bc144e22d84b0ebcb467ee99:
.. _cid-ksl_product_drinvvinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drinvvinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1acfca5a948a1b891c67fbabe61afb4f82:
.. _cid-ksl_product_drinvvinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drinvvinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a74533c22448aa1778ff734d287931ff5:
.. _cid-ksl_product_drvtx:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtx (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a895ddfe07eb888ed3d287a6da0d21b98:
.. _cid-ksl_product_drvtxf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtxf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1ac6c6d0870043eae9ac8d21170ac0f35e:
.. _cid-ksl_product_drvtxinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtxinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a20e95b864ae594011833dc0b2d58bb33:
.. _cid-ksl_product_drvtxinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtxinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a77fc0964e58b852eb9849fdc98500853:
.. _cid-ksl_product_drvty:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvty (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1adaed020b38a6b59f2b3ca909b134ab33:
.. _cid-ksl_product_drvtyf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtyf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1af0db5c28061626299de279551fdf1448:
.. _cid-ksl_product_drvtyinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtyinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a528e7cf7dd8657c1c16b2476c8e3180b:
.. _cid-ksl_product_drvtyinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtyinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a382179892501b2ca11749f8dabfff479:
.. _cid-ksl_product_drvtz:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtz (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1afea0117039f42f40c2f5a20cbeca8682:
.. _cid-ksl_product_drvtzf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtzf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a3c25a5ad0517dddf6459876b6a2aded7:
.. _cid-ksl_product_drvtzinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtzinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double ti,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a156424d82a2ec1821ddfa518de21fbdb:
.. _cid-ksl_product_drvtzinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drvtzinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float ti,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1ab28fd58fa54787c6d00e8583551f269b:
.. _cid-ksl_product_drdrx:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrx (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a841e4404e3180416561d1eb85f42f752:
.. _cid-ksl_product_drdrxf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrxf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a0f8147a0eccde2ea280f9cedf0161e41:
.. _cid-ksl_product_drdrxinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrxinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a035330469bffd88388cde0b7531b1fdd:
.. _cid-ksl_product_drdrxinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrxinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a42eb97c1b223820a1e6786e8c84a1cc6:
.. _cid-ksl_product_drdry:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdry (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1ac76d6dfd9d92929ef94bbe1a35e5ef6c:
.. _cid-ksl_product_drdryf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdryf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a7ce0d67d2bdc0d81bba7b63505a4bbaa:
.. _cid-ksl_product_drdryinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdryinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a75538fc1a0894a5281ae9b9aa4747550:
.. _cid-ksl_product_drdryinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdryinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1ad8de4524273920c39c60a682f59def10:
.. _cid-ksl_product_drdrz:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrz (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa1968e258d20b175fb2c51bef32862d3:
.. _cid-ksl_product_drdrzf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrzf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a63f176e05ec89befa6cae43281273888:
.. _cid-ksl_product_drdrzinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrzinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const double dc [2],
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a87876bb5e6f36dfb32832cb59cd59386:
.. _cid-ksl_product_drdrzinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrzinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const float dc [2],
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a9909e2688e96649fc489d4146cf76309:
.. _cid-ksl_product_drdr:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdr (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a4a10bf67a02e33862201f67be3d1e306:
.. _cid-ksl_product_drdrf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a8ab8a0fa93f7904f1383a2bd1c43d383:
.. _cid-ksl_product_drdrinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a61401166bb323fb690f17fb057b3fabc:
.. _cid-ksl_product_drdrinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drdrinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1ac7c3eb3a0a483c04849d5400f83346f7:
.. _cid-ksl_product_drinvdr:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drinvdr (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r1i,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* r2i,
	    :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1afdc3dbfcdeb378dee0d302a95ed1878e:
.. _cid-ksl_product_drinvdrf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_drinvdrf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r1i,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* r2i,
	    :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ro
	    )

TODO document this function.

.. _doxid-matrix_8h_1a89cbbe54e33d39734fad9eaf019938c1:
.. _cid-ksl_product_dv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1aae4ed7f97b099b5a91a9897df215a568:
.. _cid-ksl_product_dvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a4fd6871e4bd4853ddb181bc77f40db5c:
.. _cid-ksl_product_dinvv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dinvv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a27206827f2ee969f15c7bc77d059c41a:
.. _cid-ksl_product_dinvvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dinvvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vo
	    )

TODO document this function.

.. _doxid-matrix_8h_1a89fbbfddfa9b023c8bf59dce0f515ee6:
.. _cid-ksl_product_ddrx:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a9cc272be249bbf2610fedf23f70f5b7d:
.. _cid-ksl_product_ddrxf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1af0fe4b62b1ae13c590bec8be64771d78:
.. _cid-ksl_product_ddrxinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a95c46420eca8e31fcd7b76d41fe1143f:
.. _cid-ksl_product_ddrxinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a954264c1bc3a4e8e47e63c2682bb9090:
.. _cid-ksl_product_ddry:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddry (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a4302352cde9ca58fa87f55d93996fe9a:
.. _cid-ksl_product_ddryf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddryf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1afd619afd47692e36a9cad186fee6b687:
.. _cid-ksl_product_ddryinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddryinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1ac26fbb7270a979e832ca699ce627644b:
.. _cid-ksl_product_ddryinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddryinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a904407cfe285833aa9f070cc55e7a56e:
.. _cid-ksl_product_ddrz:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1af2a48c5e14b9e2ce6a6c4d77d2dbffac:
.. _cid-ksl_product_ddrzf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1ad08885ba5969c6662ce36aeec35e0680:
.. _cid-ksl_product_ddrzinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double dc [2],
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a2d1255d8074162eef6a5a3a8f2f8284d:
.. _cid-ksl_product_ddrzinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float dc [2],
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1ada7fc5c86c16b78c6c11c98861001d60:
.. _cid-ksl_product_ddt:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddt (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* t,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a9fe2fb618bf2b59cba070eae4e6e1df2:
.. _cid-ksl_product_ddtinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa06b5083a440f16f73d94544c058859f:
.. _cid-ksl_product_ddtinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a27b001c3020cbedebacb8498b3e03a0e:
.. _cid-ksl_product_ddtf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a2010a2f24e1da281d83db9f9f9e583cb:
.. _cid-ksl_product_dinvdt:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dinvdt (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* vi,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a1784236b926c17bf09e0ab65c2869585:
.. _cid-ksl_product_dinvdtf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dinvdtf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* vi,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a7efab3193f502c06f891011536e129dd:
.. _cid-ksl_product_ddtx:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a450a2ffc23fe16f65b453871e5e93e8e:
.. _cid-ksl_product_ddtxf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a3fabcec659331aa080eeff02bb77a195:
.. _cid-ksl_product_ddtxinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a49c127a19375005dd3dcf0db8a5f154c:
.. _cid-ksl_product_ddtxinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a868400ded32600cc2e983dbc9eb701c1:
.. _cid-ksl_product_ddty:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddty (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a7ee9767dfdf20e08d8b1128643d3b8c0:
.. _cid-ksl_product_ddtyf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtyf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a2d309b34086fe456701e99053a5fa5d5:
.. _cid-ksl_product_ddtyinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtyinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a737c7b541ba23d0f3fc924115a04b646:
.. _cid-ksl_product_ddtyinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtyinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1ad2ee354edcf8f508911f9626c042a8f5:
.. _cid-ksl_product_ddtz:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1afce7b27ccf0cdbdb464d4dde33de0925:
.. _cid-ksl_product_ddtzf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a788d88150cac3e051989b2ec9136890d:
.. _cid-ksl_product_ddtzinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const double ti,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a8e10978354a96dac2d83345517992870:
.. _cid-ksl_product_ddtzinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddtzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const float ti,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa9c8e7bdfb33c1bf5399056e863a43a5:
.. _cid-ksl_product_ddr:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddr (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1af902cbe4b9c0e2747f285607e352cc92:
.. _cid-ksl_product_ddrf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a4539c07a76339e8f140dbb84e26fe60d:
.. _cid-ksl_product_ddrinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* Ri,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a5cd6901393ac24ac3926834a39ef8d52:
.. _cid-ksl_product_ddrinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddrinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* Ri,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a15bcf0d47792c422bf2a37776d8fedf1:
.. _cid-ksl_product_dd:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_dd (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D1i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D2i,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1af3efc7b072d4ee61ec9e32934a567a52:
.. _cid-ksl_product_ddf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D1i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D2i,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1a0212b856cf24880d5a12f019dfee91bc:
.. _cid-ksl_product_ddinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D1i,
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* D2i,
	    :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Do
	    )

TODO document this function.

.. _doxid-matrix_8h_1aa551d477178695b29bd4732f0cf8f3f8:
.. _cid-ksl_product_ddinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_ddinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D1i,
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* D2i,
	    :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Do
	    )

TODO document this function.

.. _doxid-print_8h_1a2e5a1bcddc0e22def85af860db77f310:
.. _cid-ksl_print_setdefaultoptions:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setDefaultOptions ()

set global print options to default settings

.. _doxid-print_8h_1a98672fb59441c141cf749f99cb97235c:
.. _cid-ksl_print_setdelimiteroption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setDelimiterOption (
	    const char* delimiter,
	    ...
	    )

used to set delimiter used in display of matrices, vectors, etc.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - delimiter

        - [in] a

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1ac163ab31d913a151c3bde009e3d8918e:
.. _cid-ksl_print_setrealformatoption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setRealFormatOption (
	    const char* fmt,
	    ...
	    )

used to set format for display of float and double values



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - fmt

        - [in]

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1ad0388b97e6c0a0393eaac3fe964bfa95:
.. _cid-ksl_print_setinnerbracketsoption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setInnerBracketsOption (
	    const char* left,
	    const char* right,
	    ...
	    )

used to set inner brackets in dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - left

        - [in] left bracket

    *
        - right

        - [in] right bracket

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1a955148cf4e975318b12ec9c9498af32d:
.. _cid-ksl_print_setouterbracketsoption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setOuterBracketsOption (
	    const char* left,
	    const char* right,
	    ...
	    )

used to set outer brackets in dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - left

        - [in] left bracket

    *
        - right

        - [in] right bracket

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1a958c8cba13c82587a113946b0ddbad9a:
.. _cid-ksl_print_setbreakbetweenlinesinmatrixoption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setBreakBetweenLinesInMatrixOption (
	    ksl_print_breakBetweenLines_enum_t val,
	    ...
	    )

used to set "BreakBetweenLinesInMatrix" option for dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - val

        - [in] valid inputs are KSL_BREAK_BETWEEN_LINES or KSL_NO_BREAK_BETWEEN_LINES

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1a2375c5f944ce34ebe337d14c6522528e:
.. _cid-ksl_print_setbooleanoption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setBooleanOption (
	    const char* True,
	    const char* False,
	    ...
	    )

used to set display of boolean values



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - left

        - [in] string to display true values

    *
        - right

        - [in] string to display false values

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1a39ae1ab349f68f28957f6c7f74f2c117:
.. _cid-ksl_print_setrowcolumnmajorprintingoption:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_print_setRowColumnMajorPrintingOption (
	    ksl_matrix_enum_t print_row_column_major,
	    ...
	    )

used to set "RowColumnMajorPrinting" option for dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - val

        - [in] valid inputs are KSL_ROW_MAJOR or KSL_COLUMN_MAJOR

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL, the options are set in the global print options. This second argument is required in this function.

.. _doxid-print_8h_1abc715dd84d5ef70c8936ba2afc5615b4:
.. _cid-ksl_print_options:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_print_options_t<doxid-structksl__print__options__t>`*
	ksl_print_options ()

constructor used to create a default print options on the heap. must be freed by user.

.. _doxid-print_8h_1a620f9daa7305bf5d1c08da8b816201be:
.. _cid-ksl_inertia_printwithoptions:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_inertia_printWithOptions (
	    FILE* f,
	    const :ref:`ksl_inertia_t<doxid-unionksl__inertia__t>`* m,
	    ...
	    )

print a full 6x6 spatial inertia matrix

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

.. _doxid-screw_8h_1a074aa263bdba2e806f41b8c0fd70b049:
.. _cid-ksl_screw:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_screw_t<doxid-unionksl__screw__t>`
	ksl_screw (
	    const double m0,
	    const double m1,
	    const double m2,
	    const double m3,
	    const double m4,
	    const double m5
	    )

double precision screw constructor

.. _doxid-screw_8h_1a47ed7eeed2d9f65a783981f5f7af27e3:
.. _cid-ksl_screwf:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`
	ksl_screwf (
	    const float m0,
	    const float m1,
	    const float m2,
	    const float m3,
	    const float m4,
	    const float m5
	    )

single precision screw constructor

.. _doxid-screw_8h_1a4ee1e17a87eb36a6d46ea6b11207f1f1:
.. _cid-ksl_screw_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	ksl_screw_alloc (int n)

allocate n double precision screw quantities on the heap, must be freed by the user.

.. _doxid-screw_8h_1a8b961eb4dc4f53561129118e64978b32:
.. _cid-ksl_screwf_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	ksl_screwf_alloc (int n)

allocate n single precision screw quantities on the heap, must be freed by the user.

.. _doxid-screw_8h_1aff240f06e66c05e2c67bef3296110d01:
.. _cid-ksl_screw_norm:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_screw_norm (const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s)

Compute the screw norm of a double precision spatial screw.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - s

        - [in] input screw



.. rubric:: Returns:

screw norm

.. _doxid-screw_8h_1a183da8324398b1c29254ad6038a04ea6:
.. _cid-ksl_screwf_norm:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_screwf_norm (const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s)

Compute the screw norm of a single precision spatial screw.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - s

        - [in] input screw



.. rubric:: Returns:

screw norm

.. _doxid-screw_8h_1af7e64780709d753afc65964a29b2d202:
.. _cid-ksl_screw_normalize:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screw_normalize (:ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s)

TODO document this function.

.. _doxid-screw_8h_1a34cae9d994d45ddeb3350f721a653939:
.. _cid-ksl_screwf_normalize:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screwf_normalize (:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s)

TODO document this function.

.. _doxid-screw_8h_1aba24696734f91f274a313fcded239a9f:
.. _cid-ksl_screw_normalized:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screw_normalized (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a331cf06b3df89b266aefc72ec88b51cb:
.. _cid-ksl_screwf_normalized:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screwf_normalized (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a1e16e01205618ecbb97ce9354a064eb5:
.. _cid-ksl_dot_cs:
.. ref-code-block:: cpp
	:class: title-code-block

	double
	ksl_dot_cs (
	    const :ref:`ksl_coscrew_t<doxid-unionksl__coscrew__t>`* ci,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si
	    )

compute double precision dot product between a coscrew and screw

.. _doxid-screw_8h_1a6573ab37452003260c07690964c1d5aa:
.. _cid-ksl_dot_csf:
.. ref-code-block:: cpp
	:class: title-code-block

	float
	ksl_dot_csf (
	    const :ref:`ksl_coscrewf_t<doxid-unionksl__coscrewf__t>`* ci,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si
	    )

compute single precision dot product between a coscrew and screw

.. _doxid-screw_8h_1ace8288864ae74b66f23d5c80d8e32e36:
.. _cid-ks_screw_scale:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ks_screw_scale (
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`,
	    const double
	    )

TODO document this function.

.. _doxid-screw_8h_1acb56e1c2c428883359aa0bd2186d6ff3:
.. _cid-ks_screwf_scale:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ks_screwf_scale (
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`,
	    const float
	    )

TODO document this function.

.. _doxid-screw_8h_1a5c6f25b9ffae60a91a462cda40136fa7:
.. _cid-ksl_screw_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screw_copy (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

Copy double precision :ref:`ksl_screw_t <doxid-unionksl__screw__t>` si to so.

$S_i \rightarrow S_o$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - si

        - [in] screw to copy

    *
        - so

        - [out] si is copied to so

.. _doxid-screw_8h_1a9b38f6219c0b2ad9504d5d1a9c7c652f:
.. _cid-ksl_screwf_copy:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screwf_copy (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

Copy single precision :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` si to so.

$S_i \rightarrow S_o$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - si

        - [in] screw to copy

    *
        - so

        - [out] si is copied to so

.. _doxid-screw_8h_1a3b1aea456f3d39464b038afc44fb97f1:
.. _cid-ksl_screw_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screw_invert (:ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si)

Invert (i.e. negate) a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` in place.

$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}$ $-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - si

        - [in/out] screw to invert

.. _doxid-screw_8h_1a6405e06d36986bdcd43fce3084c24461:
.. _cid-ksl_screwf_invert:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screwf_invert (:ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si)

Invert (i.e. negate) a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` in place.

$\mathbf{\underline{s}}^{-1} \rightarrow \mathbf{\underline{s}}$ $-\mathbf{\underline{s}} \rightarrow \mathbf{\underline{s}}$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - si

        - [in/out] screw to invert

.. _doxid-screw_8h_1aa2765f5d941bc8d85286a06ba74f3669:
.. _cid-ksl_screw_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screw_inverted (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

Returns the inverse of a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` .

$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - si

        - [in] screw to invert

    *
        - so

        - [out] inverse of si

.. _doxid-screw_8h_1a0009bdfe7542a64fc2383d193c8c202d:
.. _cid-ksl_screwf_inverted:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_screwf_inverted (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

Returns the inverse of a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` .

$\mathbf{\underline{s}}_i^{-1} \rightarrow \mathbf{\underline{s}}_o$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - si

        - [in] screw to invert

    *
        - so

        - [out] inverse of si

.. _doxid-screw_8h_1a9b90bf999e5c58cfcb8c238a68a99771:
.. _cid-ksl_product_as:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_as (
	    const double k,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a820e13bbb612f278942f5a71ef24f9ab:
.. _cid-ksl_product_asf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_asf (
	    const float k,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1abcab2c37336344271936eca5eebd07b7:
.. _cid-ksl_axpy_ss:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_axpy_ss (
	    const double,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

compute axpy (a \* x + y  y) operation for double precision screws

.. _doxid-screw_8h_1ade69b9088fef0ec2689b3c9ce60472f7:
.. _cid-ksl_axpy_ssf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_axpy_ssf (
	    const float,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

compute axpy (a \* x + y  y) operation for single precision screws

.. _doxid-screw_8h_1a030fb18f21d0e205b91e9a43fa72952e:
.. _cid-ksl_xpy_ss:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_xpy_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

TODO document this function.

.. _doxid-screw_8h_1a3c7c48bc899eec2ba4d654316e860f8b:
.. _cid-ksl_xpy_ssf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_xpy_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

TODO document this function.

.. _doxid-screw_8h_1aed7ec16489a53e348a93db9e61e4302e:
.. _cid-ksl_nxpy_ss:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_nxpy_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`*
	    )

TODO document this function.

.. _doxid-screw_8h_1a06f69525c025aff9c5ad730dfd4d1441:
.. _cid-ksl_nxpy_ssf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_nxpy_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`*
	    )

TODO document this function.

.. _doxid-screw_8h_1a8eb9d4d35c89e369b2f2fd2a4af5edfb:
.. _cid-ksl_add_ss:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_add_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a3c9494d3792e49454c7fbb3ac2d89352:
.. _cid-ksl_add_ssf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_add_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1aa9fa9d761704fa1153f623507352348d:
.. _cid-ksl_subtract_ss:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_subtract_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1ad86f76d66b897618d6e0bce5a9edde02:
.. _cid-ksl_subtract_ssf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_subtract_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a694609a9973a623afeefda1bc064dae2:
.. _cid-ksl_add_sst:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_add_sst (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si1,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si2,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1ae4371aea3644d376a82ecf329ce934fb:
.. _cid-ksl_add_sstf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_add_sstf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si1,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si2,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1afe2ef0d4a1122930410c642897d98c38:
.. _cid-ksl_htx:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a1f13aea633ae9ca05fd505ee42438a9c:
.. _cid-ksl_htxf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a1847fad4a681462988904e25470334fc:
.. _cid-ksl_hty:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hty (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1ab5097bed364627bfafd5d2ffc1a65c21:
.. _cid-ksl_htyf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htyf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a6c9fd5d6bda14c8776a9039da9c68edb:
.. _cid-ksl_htz:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* ri,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1afb53bc09a2fd5ccacb58a3d3a59e2cda:
.. _cid-ksl_htzf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* ri,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1ab5fbd0fad8e93a98f1739d487548baab:
.. _cid-ksl_hrx:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrx (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a52cb7ed0ef48209762827917f7628ca2:
.. _cid-ksl_hrxf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrxf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a34682efe1a0b82d7922aa422b30fb337:
.. _cid-ksl_hry:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hry (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a6e29c843495c725418296b2c644b67e1:
.. _cid-ksl_hryf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hryf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a12134a4aa42f6da6b546e1310075236b:
.. _cid-ksl_hrz:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrz (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a26a98b68c63a0fae907df9a1e8bd8fb8:
.. _cid-ksl_hrzf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrzf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a64e6347999ca22e50bcc471cd0c0e35e:
.. _cid-ksl_htxinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1ab0f67034f70fb3b1d32b6bebd0935b7f:
.. _cid-ksl_htxinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a518f1c41de8bb4b75fcfeb4835f262c2:
.. _cid-ksl_htyinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htyinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a89fe85bfca60c9b6b08952749fb44d31:
.. _cid-ksl_htyinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htyinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a913fceabb404e4a65e7a8f397207a760:
.. _cid-ksl_htzinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a870420bb6b1ccd4c7ff6e343d78c5b28:
.. _cid-ksl_htzinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_htzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1ae03a4efc62eb052700680af0a562b1ec:
.. _cid-ksl_hrxinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrxinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1aef7516989eb0ce1827d94389afb34d79:
.. _cid-ksl_hrxinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrxinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a644b5464130512659a1231f13916e7ed:
.. _cid-ksl_hryinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hryinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1aa704f202430c33b994ad397702e73b54:
.. _cid-ksl_hryinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hryinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1ad8858eccb5fa00cbba06989f3d362ead:
.. _cid-ksl_hrzinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrzinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a41cf5ba358ed78f8a40201b7074dc309:
.. _cid-ksl_hrzinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_hrzinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* ho
	    )

TODO document this function.

.. _doxid-screw_8h_1a3f90c6d736fcf3adcc7cede0de5ac98d:
.. _cid-ksl_cross_ss:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_cross_ss (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

double precision screw cross product

.. _doxid-screw_8h_1ac66af38b3761c8d4bf0f56fa4c248385:
.. _cid-ksl_cross_ssf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_cross_ssf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

single precision screw cross product

.. _doxid-screw_8h_1a92a2407b4024712b0fbee78f896ed203:
.. _cid-ksl_cross_sst:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_cross_sst (
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s1i,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* s2i,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1ab77558baa443db0a9ac3003b2e5fe8c0:
.. _cid-ksl_cross_sstf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_cross_sstf (
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s1i,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* s2i,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a22606f0ceb8788b12eb25a20d38be7a1:
.. _cid-ksl_product_adrs:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adrs (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

rotates a double precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

$ R_i \* S_i[0:2] \rightarrow S_o[0:2]$

$ R_i \* S_i[3:5] \rightarrow S_o[3:5]$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ri

        - a SO3 rotation matrix

    *
        - si

        - a 1x6 screw

    *
        - so

        - the output of ri \* si is returned in so

.. _doxid-screw_8h_1ae2aa2e7020f68dd9b4716b9400cc754e:
.. _cid-ksl_product_adrsinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adrsinv (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a3c6d2dedcb47ca15e4dfa198f84a6a44:
.. _cid-ksl_product_adrsf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adrsf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

rotates a single precision screw

Store product of direction cosine matrix ri with spatial vector si in so.

$ R_i \* S_i[0:2] \rightarrow S_o[0:2]$

$ R_i \* S_i[3:5] \rightarrow S_o[3:5]$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ri

        - a SO3 rotation matrix

    *
        - si

        - a 1x6 screw

    *
        - so

        - the output of ri \* si is returned in so

.. _doxid-screw_8h_1ac1c548130b277dc68ed9c72bff498030:
.. _cid-ksl_product_adrsinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adrsinvf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1aadc61d866d74258ccc9bdfe151213ff8:
.. _cid-ksl_product_adrinvs:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adrinvs (
	    const :ref:`ksl_mat3x3_t<doxid-unionksl__mat3x3__t>`* ri,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a5f1226ded1159f5695a22f944302f418:
.. _cid-ksl_product_adrinvsf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adrinvsf (
	    const :ref:`ksl_mat3x3f_t<doxid-unionksl__mat3x3f__t>`* ri,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1ad608d5b26172dbcc52dbd454b664e693:
.. _cid-ksl_product_adts:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adts (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a3d09944886b213613b15da820f5f74ef:
.. _cid-ksl_product_adtsf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adtsf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1aff6e27f1af1f740ab4ff3319a74b3a69:
.. _cid-ksl_product_adtinvs:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adtinvs (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1aa9f5f696af95682f42ffdef47ba0dbc6:
.. _cid-ksl_product_adtinvsf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adtinvsf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1ac01634179e19f20f6bd8c7cbc597437d:
.. _cid-ksl_product_adtsinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adtsinv (
	    const :ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`* ti,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a3dabab03e28df14d9bd91f67e6d9061f:
.. _cid-ksl_product_adtsinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adtsinvf (
	    const :ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`* ti,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a1d19786f414359ed21a6649d8be99e57:
.. _cid-ksl_product_ads:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Ads (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

General spatial transformation a double precision screw.

Store product of direction cosine matrix ri with spatial vector si in so.

$ R_i \* S_i[0:2] \rightarrow S_o[0:2]$

$ R_i \* S_i[3:5] \rightarrow S_o[3:5]$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ri

        - a SO3 rotation matrix

    *
        - si

        - a 1x6 screw

    *
        - so

        - the output of ri \* si is returned in so

.. _doxid-screw_8h_1ac9de2b0dfe4e74cf65f3238c0745a675:
.. _cid-ksl_product_adsinv:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adsinv (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1acf2c57239c0478f7b9f435aa76c04589:
.. _cid-ksl_product_adsinvf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adsinvf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a14769fe5e3c6d68015c47bfebecd6b24:
.. _cid-ksl_product_adsf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adsf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

General spatial transformation a single precision screw.

Store product of direction cosine matrix ri with spatial vector si in so.

$ R_i \* S_i[0:2] \rightarrow S_o[0:2]$

$ R_i \* S_i[3:5] \rightarrow S_o[3:5]$



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - ri

        - a SO3 rotation matrix

    *
        - si

        - a 1x6 screw

    *
        - so

        - the output of ri \* si is returned in so

.. _doxid-screw_8h_1a66239941994450b928f4ce8fd2016f2c:
.. _cid-ksl_product_adinvs:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adinvs (
	    const :ref:`ksl_SE3_t<doxid-unionksl___s_e3__t>`* Di,
	    const :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* si,
	    :ref:`ksl_screw_t<doxid-unionksl__screw__t>`* so
	    )

TODO document this function.

.. _doxid-screw_8h_1a15fa0415230d31423d5d363ccaa73d62:
.. _cid-ksl_product_adinvsf:
.. ref-code-block:: cpp
	:class: title-code-block

	void
	ksl_product_Adinvsf (
	    const :ref:`ksl_SE3f_t<doxid-unionksl___s_e3f__t>`* Di,
	    const :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* si,
	    :ref:`ksl_screwf_t<doxid-unionksl__screwf__t>`* so
	    )

TODO document this function.

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

.. _doxid-vector_8h_1ad5d4b78eae694f6831e6a5df916a6eda:
.. _cid-ksl_vec3:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3_t<doxid-unionksl__vec3__t>`
	ksl_vec3 (
	    const double x,
	    const double y,
	    const double z
	    )

vec3 constructor

.. _doxid-vector_8h_1a8c1da367b7daa11d0f3ed63ae50712ce:
.. _cid-ksl_vec3f:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3f_t<doxid-unionksl__vec3f__t>`
	ksl_vec3f (
	    const float x,
	    const float y,
	    const float z
	    )

vec3f constructor

.. _doxid-vector_8h_1aa432faefe6257a90d3245b9ac54fed54:
.. _cid-ksl_vec3i:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec3i_t<doxid-unionksl__vec3i__t>`
	ksl_vec3i (
	    const int x,
	    const int y,
	    const int z
	    )

vec3i constructor

.. _doxid-vector_8h_1afd6bb01fca0d56d7514eae51b205c9a7:
.. _cid-ksl_vec4:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`
	ksl_vec4 (
	    const double x,
	    const double y,
	    const double z,
	    const double w
	    )

vec4 constructor

.. _doxid-vector_8h_1a54c592f1f7175d5a77a9ca3bd6af1181:
.. _cid-ksl_vec4f:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`
	ksl_vec4f (
	    const float x,
	    const float y,
	    const float z,
	    const float w
	    )

vec4f constructor

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

.. _doxid-vector_8h_1ad8219bcf00ad612fa1791efff35c0a54:
.. _cid-ksl_vec4_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec4_t<doxid-unionksl__vec4__t>`*
	ksl_vec4_alloc (int)

initialize n :ref:`ksl_vec4_t <doxid-unionksl__vec4__t>` double precision vectors datastructures on the heap

.. _doxid-vector_8h_1a67c0ecb326dd2dd17cb2467e2c33f067:
.. _cid-ksl_vec4f_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec4f_t<doxid-unionksl__vec4f__t>`*
	ksl_vec4f_alloc (int)

initialize n :ref:`ksl_vec4f_t <doxid-unionksl__vec4f__t>` single precision vectors datastructures on the heap

.. _doxid-vector_8h_1a6942778c81cae89afc59b8e78381dec7:
.. _cid-ksl_vec4i_alloc:
.. ref-code-block:: cpp
	:class: title-code-block

	:ref:`ksl_vec4i_t<doxid-unionksl__vec4i__t>`*
	ksl_vec4i_alloc (int)

initialize n :ref:`ksl_vec4i_t <doxid-unionksl__vec4i__t>` vectors of integers on the heap

Macros
------

.. _doxid-ksl_8h_1a90bb91d1c207348b1765693fedacdf85:
.. _cid-_ksl_h_:
.. ref-code-block:: cpp
	:class: title-code-block

	#define _KSL_H_

KSL: Kinematics Subroutine Library Kristopher Wehage, Roger Wehage

Kristopher Wehage, Roger Wehage

.. _doxid-print_8h_1aa4b538500dcedc748c4aa6c693b10b49:
.. _cid-ksl_se3_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_SE3_debug(f, m, ...)

"debug" print a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` in release mode, use the ksl_SE3_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a8341812ecc6045c1ad52d301e836751f:
.. _cid-ksl_se3_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_SE3_print(f, m, ...)

print a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_SE3_t <doxid-unionksl___s_e3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a5049da03b9f0cc1fee07384d41b71d82:
.. _cid-ksl_se3f_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_SE3f_debug(f, m, ...)

"debug" print a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` in release mode, use the ksl_SE3f_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a25bc4d224bdd04adbaf3d31586b3c754:
.. _cid-ksl_se3f_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_SE3f_print(f, m, ...)

print a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_SE3f_t <doxid-unionksl___s_e3f__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a7a3b5c0c2b87a097489948f230c0932a:
.. _cid-ksl_array2d_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_array2D_debug(f, m, n, a, ...)

"debug" print a double precision 2D array. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_array_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - m

        - [in] array row dimension

    *
        - n

        - [in] array column dimension

    *
        - a

        - [in] a pointer to a double\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1abbdc75045ba05ed66d03becef8b3d854:
.. _cid-ksl_array2d_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_array2D_print(f, m, n, a, ...)

print a double precision 2D array.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - m

        - [in] row dimension

    *
        - n

        - [in] column dimension

    *
        - a

        - [in] a pointer to a double\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a28197a9dd99c053d29e1bd470250ffbd:
.. _cid-ksl_array_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_array_debug(f, n, a, ...)

"debug" print a double precision array. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_array_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] number of values to print

    *
        - a

        - [in] a pointer to a double\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a712761955bd5302e081d971f072cda4e:
.. _cid-ksl_array_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_array_print(f, n, a, ...)

print a double precision array.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] number of values to print

    *
        - a

        - [in] a pointer to a double\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1ae7918065a65b86589495e5765d584ab2:
.. _cid-ksl_arrayi_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_arrayi_debug(f, n, a, ...)

"debug" print an array of integers. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_arrayi_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] number of values to print

    *
        - a

        - [in] a pointer to a double\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a4bb299446d942f72d05f014a43e8cef8:
.. _cid-ksl_arrayi_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_arrayi_print(f, n, a, ...)

print an array of integers.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] number of values to print

    *
        - a

        - [in] a pointer to a int\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a49b77ed4e5568d676402ee85eb097539:
.. _cid-ksl_coscrew_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_coscrew_debug(f, v, ...)

"debug" print a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` in release mode, use the ksl_coscrew_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1ae6f445427223d0e2d1c5fc8754d01607:
.. _cid-ksl_coscrew_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_coscrew_print(f, v, ...)

print a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_coscrew_t <doxid-unionksl__coscrew__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1aba5a25f4159556dd2619e6152b681c47:
.. _cid-ksl_coscrewf_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_coscrewf_debug(f, v, ...)

"debug" print a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` in release mode, use the ksl_coscrewf_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a661e7a6a2bd86c5b4c47308b44c2d463:
.. _cid-ksl_coscrewf_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_coscrewf_print(f, v, ...)

print a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_coscrewf_t <doxid-unionksl__coscrewf__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1ae2e245ebb9d399be3eaf3a8db86a208a:
.. _cid-ksl_inertia_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_inertia_debug(f, m, ...)

"debug" print a triangular array of boolean values. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_triangb_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a boolean array

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1ae7c99f22b93093fe89fdd76073c32f69:
.. _cid-ksl_inertia_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_inertia_print(f, m, ...)

print a lower triangular array of booleans.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a boolean array

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a6b1f1f1327bb35346be81d6d8a57a683:
.. _cid-ksl_mat3x3_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat3x3_debug(f, m, ...)

"debug" print a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` in release mode, use the ksl_mat3x3_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-matrix_8h_1a075673d8b8724b0b149e3d2444a81d2e:
.. _cid-ksl_mat3x3_geteulerangles:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat3x3_getEulerAngles(r, angles, axisType, ...)

macro used obtain Euler angles, allows optionally passing in reference angles from a previous nearby pose to ensure continuity in angles between adjacent poses



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - r

        - [in] rotation matrix

    *
        - angles

        - [out] euler angles returned in angles

    *
        - axisType

        - [in] a ksl_axis_enum_t type specifying Euler angle axis sequence.

    *
        - reference_angles

        - [optional] euler angles from a previous nearby pose

.. _doxid-print_8h_1a18c6ce31ebb6566618c2c37c8880e78d:
.. _cid-ksl_mat3x3_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat3x3_print(f, m, ...)

print a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] an optional pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a724108f99723d9c533f5e7271021beb0:
.. _cid-ksl_mat3x3f_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat3x3f_debug(f, m, ...)

"debug" print a :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` in release mode, use the ksl_mat3x3f_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-matrix_8h_1a7f9d70aa654ca2ec9834920e6513e098:
.. _cid-ksl_mat3x3f_geteulerangles:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat3x3f_getEulerAngles(r, angles, axisType, ...)

macro used obtain Euler angles from a single precision rotation matrix, allows optionally passing in reference angles from a previous nearby pose to ensure continuity in angles between adjacent poses



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - r

        - [in] rotation matrix

    *
        - angles

        - [out] euler angles returned in angles

    *
        - axisType

        - [in] a ksl_axis_enum_t type specifying Euler angle axis sequence.

    *
        - reference_angles

        - [optional] euler angles from a previous nearby pose

.. _doxid-print_8h_1a771b950c28c042929e799a14c77ae5ce:
.. _cid-ksl_mat3x3f_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat3x3f_print(f, m, ...)

print a :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat3x3f_t <doxid-unionksl__mat3x3f__t>` datastructure

    *
        - label

        - [in] an optional pointer to a const char\* label

    *
        - options

        - [in] an optional pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1afe715b05556f3b8df30de17d961c7b4e:
.. _cid-ksl_mat4x4_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat4x4_debug(f, m, ...)

"debug" print a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` in release mode, use the ksl_mat4x4_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a03bac481a25734bb765ba996a0ad7e1d:
.. _cid-ksl_mat4x4_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat4x4_print(f, m, ...)

print a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a783d3c350c41f613316ef9640e08638c:
.. _cid-ksl_mat4x4f_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat4x4f_debug(f, m, ...)

"debug" print a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_mat4x4_t <doxid-unionksl__mat4x4__t>` in release mode, use the ksl_mat4x4_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat3x3_t <doxid-unionksl__mat3x3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1af5b884b620ce8e7b102e803297497629:
.. _cid-ksl_mat4x4f_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_mat4x4f_print(f, m, ...)

print a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_mat4x4f_t <doxid-unionksl__mat4x4f__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1acfd020e2a5856dbaf67fcc5dbc82a7b3:
.. _cid-ksl_print_setboolean:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setBoolean(True, False, ...)

used to set "BreakBetweenLinesInMatrix" option for dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - val

        - [in] valid inputs are KSL_BREAK_BETWEEN_LINES or KSL_NO_BREAK_BETWEEN_LINES

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1acb24ebe9339505b1f9480f2004f20aba:
.. _cid-ksl_print_setbreakbetweenlinesinmatrix:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setBreakBetweenLinesInMatrix(val, ...)

used to set "BreakBetweenLinesInMatrix" option for dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - val

        - [in] valid inputs are KSL_BREAK_BETWEEN_LINES or KSL_NO_BREAK_BETWEEN_LINES

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1ab010c85ae8e4338222e9e8d91faac823:
.. _cid-ksl_print_setdelimiter:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setDelimiter(fmt, ...)

used to set delimiter used in display of matrices, vectors, screws, etc.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - delimiter

        - [in]

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1a79251216895c5881dafd7edcd643eac6:
.. _cid-ksl_print_setinnerbrackets:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setInnerBrackets(left, right, ...)

used to set inner brackets in dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - left

        - [in] left bracket

    *
        - right

        - [in] right bracket

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1af5093b92d7af83b8bea2e590739299e4:
.. _cid-ksl_print_setouterbrackets:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setOuterBrackets(left, right, ...)

used to set outer brackets in dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - left

        - [in] left bracket

    *
        - right

        - [in] right bracket

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1a4af08209f3477f54aecc407683913f18:
.. _cid-ksl_print_setrealformat:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setRealFormat(fmt, ...)

used to set format for display of float and double values



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - fmt

        - [in]

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1a16bda9a363d071b0c70d55d16d898f53:
.. _cid-ksl_print_setrowcolumnmajorprinting:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_print_setRowColumnMajorPrinting(val, ...)

used to set "RowColumnMajorPrinting" option for dispay of matrices



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - val

        - [in] valid inputs are KSL_ROW_MAJOR or KSL_COLUMN_MAJOR

    *
        - options

        - [in] a pointer to a user-defined :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If this value is NULL or is not present, the option will be set in the global print settings.

.. _doxid-print_8h_1a38c97b7f4dcb5c7fb9b9c81ebdcede4c:
.. _cid-ksl_quaternion_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_quaternion_debug(f, v, ...)

"debug" print a :ref:`ksl_quaternion_t <doxid-unionksl__quaternion__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_quaternion_t <doxid-unionksl__quaternion__t>` in release mode, use the ksl_quaternion_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_quaternion_t <doxid-unionksl__quaternion__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1ac508dd666c45837a5c0d16ab4a3b1cf1:
.. _cid-ksl_quaternion_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_quaternion_print(f, v, ...)

print a :ref:`ksl_quaternion_t <doxid-unionksl__quaternion__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_quaternion_t <doxid-unionksl__quaternion__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a81b9eeafd87b9e982c9d041caab8e4c0:
.. _cid-ksl_quaternionf_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_quaternionf_debug(f, v, ...)

"debug" print a :ref:`ksl_quaternionf_t <doxid-unionksl__quaternionf__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_quaternionf_t <doxid-unionksl__quaternionf__t>` in release mode, use the ksl_quaternionf_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_quaternionf_t <doxid-unionksl__quaternionf__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1acca71a66e0f48aa386fcd5377ce7f1d2:
.. _cid-ksl_quaternionf_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_quaternionf_print(f, v, ...)

print a :ref:`ksl_quaternionf_t <doxid-unionksl__quaternionf__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_quaternionf_t <doxid-unionksl__quaternionf__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a8a08b99ccf7c7fdbc08a2cdd8962af09:
.. _cid-ksl_screw_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_screw_debug(f, v, ...)

"debug" print a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` in release mode, use the ksl_screw_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a5ef0d742cbe275d37160d54ac8f0054d:
.. _cid-ksl_screw_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_screw_print(f, v, ...)

print a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_screw_t <doxid-unionksl__screw__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a181f87a35a8e7ef0032a8be990fb8b8d:
.. _cid-ksl_screwf_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_screwf_debug(f, v, ...)

"debug" print a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` in release mode, use the ksl_screwf_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a5fad2258b319563e23fb14457c555d3c:
.. _cid-ksl_screwf_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_screwf_print(f, v, ...)

print a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_screwf_t <doxid-unionksl__screwf__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1ae40e8dd8eb231d6d673dd60944e91c0b:
.. _cid-ksl_triang_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_triang_debug(f, n, a, ...)

"debug" print a triangular array of double precision values. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_triang_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a double\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a08e9ed87ddebcbdd9ee450be90b1f424:
.. _cid-ksl_triang_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_triang_print(f, n, a, ...)

print a lower triangular array of double precision values.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a int\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a0f460fb54e7e5c54c17df6f7b8cf6384:
.. _cid-ksl_triangb_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_triangb_debug(f, n, a, ...)

"debug" print a triangular array of boolean values. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_triangb_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a boolean array

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a55d42c68196b42a9580a82b750aa3aee:
.. _cid-ksl_triangb_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_triangb_print(f, n, a, ...)

print a lower triangular array of booleans.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a boolean array

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a1ebaf4f2934b344d11ac213143bd9502:
.. _cid-ksl_triangi_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_triangi_debug(f, n, a, ...)

"debug" print a triangular array of integer values. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print an array in release mode, use the ksl_triangi_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a int\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a414a80b40c3bd652375f42a6f303d575:
.. _cid-ksl_triangi_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_triangi_print(f, n, a, ...)

print a lower triangular array of integers.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - n

        - [in] row/column dimension of nxn matrix

    *
        - a

        - [in] a pointer to a int\*

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a62c27e70109cee505d2045a82ed32f38:
.. _cid-ksl_vec3_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_vec3_debug(f, v, ...)

"debug" print a :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` in release mode, use the ksl_vec3_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a168f87276c6b1fc784e6061b84595c72:
.. _cid-ksl_vec3_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_vec3_print(f, v, ...)

print a :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_vec3_t <doxid-unionksl__vec3__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options. To pass an options struct with no label, call :ref:`ksl_vec3_print(f, v, NULL, options) <doxid-print_8h_1a168f87276c6b1fc784e6061b84595c72>` ; or ksl_vec3_print(f, v, "", options);

.. _doxid-print_8h_1a887a09b118189ce62ab9d2537b7e86f0:
.. _cid-ksl_vec3f_debug:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_vec3f_debug(f, v, ...)

"debug" print a :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` data structure. If NDEBUG is defined, this function is converted to a no-op and nothing will be output. If it is desired to print a :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` in release mode, use the ksl_vec3f_print function.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options.

.. _doxid-print_8h_1a59940cf406975811638e5472b3ffee99:
.. _cid-ksl_vec3f_print:
.. ref-code-block:: cpp
	:class: title-code-block

	#define ksl_vec3f_print(f, v, ...)

print a :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` data structure.



.. rubric:: Parameters:

.. list-table::
    :widths: 20 80

    *
        - f

        - [in] a file pointer (e.g. stdout, stderr, etc.)

    *
        - v

        - [in] a pointer to a :ref:`ksl_vec3f_t <doxid-unionksl__vec3f__t>` datastructure

    *
        - label

        - [in] optional pointer to a const char\* label

    *
        - options

        - [in] a pointer to a :ref:`ksl_print_options_t <doxid-structksl__print__options__t>` struct containing print options. If the pointer is NULL or not present, the options are set in the global print options. To pass an options struct with no label, call :ref:`ksl_vec3f_print(f, v, NULL, options) <doxid-print_8h_1a59940cf406975811638e5472b3ffee99>` ; or ksl_vec3f_print(f, v, "", options);

