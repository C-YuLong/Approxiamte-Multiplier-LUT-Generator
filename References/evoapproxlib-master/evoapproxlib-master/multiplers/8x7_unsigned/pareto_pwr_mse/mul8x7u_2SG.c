/***
* This code is a part of EvoApproxLib library (ehw.fit.vutbr.cz/approxlib) distributed under The MIT License.
* When used, please cite the following article(s): V. Mrazek, L. Sekanina, Z. Vasicek "Libraries of Approximate Circuits: Automated Design and Application in CNN Accelerators" IEEE Journal on Emerging and Selected Topics in Circuits and Systems, Vol 10, No 4, 2020 
* This file contains a circuit from a sub-set of pareto optimal circuits with respect to the pwr and mse parameters
***/
// MAE% = 0.00057 %
// MAE = 0.19 
// WCE% = 0.0031 %
// WCE = 1.0 
// WCRE% = 100.00 %
// EP% = 18.75 %
// MRE% = 0.028 %
// MSE = 0.19 
// PDK45_PWR = 0.330 mW
// PDK45_AREA = 600.7 um2
// PDK45_DELAY = 1.36 ns
#include <stdint.h>
#include <stdlib.h>

uint64_t mul8x7u_2SG(const uint64_t A /* 8-bit unsigned operand */, const uint64_t B /* 7-bit unsigned operand */)
{
   uint64_t dout_16, dout_17, dout_18, dout_19, dout_20, dout_21, dout_22, dout_23, dout_24, dout_25, dout_26, dout_27, dout_28, dout_29, dout_30, dout_31, dout_32, dout_33, dout_34, dout_35, dout_36, dout_37, dout_38, dout_39, dout_40, dout_41, dout_42, dout_43, dout_44, dout_45, dout_46, dout_47, dout_48, dout_49, dout_50, dout_51, dout_52, dout_53, dout_54, dout_55, dout_56, dout_57, dout_58, dout_59, dout_60, dout_61, dout_62, dout_63, dout_64, dout_65, dout_66, dout_67, dout_68, dout_69, dout_70, dout_71, dout_72, dout_73, dout_74, dout_75, dout_76, dout_77, dout_78, dout_79, dout_80, dout_81, dout_82, dout_83, dout_84, dout_85, dout_86, dout_87, dout_88, dout_89, dout_90, dout_91, dout_92, dout_93, dout_94, dout_95, dout_96, dout_97, dout_98, dout_99, dout_100, dout_101, dout_102, dout_103, dout_104, dout_105, dout_106, dout_107, dout_108, dout_109, dout_110, dout_111, dout_112, dout_113, dout_114, dout_115, dout_116, dout_117, dout_118, dout_119, dout_120, dout_121, dout_122, dout_123, dout_124, dout_125, dout_126, dout_127, dout_128, dout_129, dout_130, dout_131, dout_132, dout_133, dout_134, dout_135, dout_136, dout_137, dout_138, dout_139, dout_140, dout_141, dout_142, dout_143, dout_144, dout_145, dout_146, dout_147, dout_148, dout_149, dout_150, dout_151, dout_152, dout_153, dout_154, dout_155, dout_156, dout_157, dout_158, dout_159, dout_160, dout_161, dout_162, dout_163, dout_164, dout_165, dout_166, dout_167, dout_168, dout_169, dout_170, dout_171, dout_172, dout_173, dout_174, dout_175, dout_176, dout_177, dout_178, dout_179, dout_180, dout_181, dout_182, dout_183, dout_184, dout_185, dout_186, dout_187, dout_188, dout_189, dout_190, dout_191, dout_192, dout_193, dout_194, dout_195, dout_196, dout_197, dout_198, dout_199, dout_200, dout_201, dout_202, dout_203, dout_204, dout_205, dout_206, dout_207, dout_208, dout_209, dout_210, dout_211, dout_212, dout_213, dout_214, dout_215, dout_216, dout_217, dout_218, dout_219, dout_220, dout_221, dout_222, dout_223, dout_224, dout_225, dout_226, dout_227, dout_228, dout_229, dout_230, dout_231, dout_232, dout_233, dout_234, dout_235, dout_236, dout_237, dout_238, dout_239, dout_240, dout_241, dout_242, dout_243, dout_244, dout_245, dout_246, dout_247, dout_248, dout_249, dout_250, dout_251, dout_252, dout_253, dout_254, dout_255, dout_256, dout_257, dout_258, dout_259, dout_260, dout_261, dout_262, dout_263, dout_264, dout_265, dout_266, dout_267, dout_268, dout_269, dout_270, dout_271, dout_272, dout_273, dout_274, dout_275, dout_276, dout_277, dout_278, dout_279, dout_280, dout_281, dout_282, dout_283, dout_284, dout_285, dout_286, dout_287, dout_288, dout_289, dout_290, dout_291, dout_292, dout_293, dout_294, dout_295, dout_296, dout_297, dout_298, dout_301, dout_302, dout_303, dout_305, dout_306, dout_308, dout_309, dout_310, dout_311, dout_312, dout_313, dout_314, dout_315, dout_316, dout_319, dout_320;
   uint64_t O;

   dout_16=((A >> 1)&1)&((B >> 0)&1);
   dout_17=((A >> 2)&1)&((B >> 0)&1);
   dout_18=((A >> 3)&1)&((B >> 0)&1);
   dout_19=((A >> 4)&1)&((B >> 0)&1);
   dout_20=((A >> 5)&1)&((B >> 0)&1);
   dout_21=((A >> 6)&1)&((B >> 0)&1);
   dout_22=((A >> 7)&1)&((B >> 0)&1);
   dout_23=((A >> 0)&1)&((B >> 1)&1);
   dout_24=((A >> 1)&1)&((B >> 1)&1);
   dout_25=((A >> 2)&1)&((B >> 1)&1);
   dout_26=((A >> 3)&1)&((B >> 1)&1);
   dout_27=((A >> 4)&1)&((B >> 1)&1);
   dout_28=((A >> 5)&1)&((B >> 1)&1);
   dout_29=((A >> 6)&1)&((B >> 1)&1);
   dout_30=((A >> 7)&1)&((B >> 1)&1);
   dout_31=dout_16&dout_23;
   dout_32=dout_16^dout_23;
   dout_33=dout_17&dout_24;
   dout_34=dout_17^dout_24;
   dout_35=dout_18&dout_25;
   dout_36=dout_18^dout_25;
   dout_37=dout_19&dout_26;
   dout_38=dout_19^dout_26;
   dout_39=dout_20&dout_27;
   dout_40=dout_20^dout_27;
   dout_41=dout_21&dout_28;
   dout_42=dout_21^dout_28;
   dout_43=dout_22&dout_29;
   dout_44=dout_22^dout_29;
   dout_45=((A >> 0)&1)&((B >> 2)&1);
   dout_46=((A >> 1)&1)&((B >> 2)&1);
   dout_47=((A >> 2)&1)&((B >> 2)&1);
   dout_48=((A >> 3)&1)&((B >> 2)&1);
   dout_49=((A >> 4)&1)&((B >> 2)&1);
   dout_50=((A >> 5)&1)&((B >> 2)&1);
   dout_51=((A >> 6)&1)&((B >> 2)&1);
   dout_52=((A >> 7)&1)&((B >> 2)&1);
   dout_53=dout_34^dout_45;
   dout_54=dout_34&dout_45;
   dout_55=dout_53&dout_31;
   dout_56=dout_53^dout_31;
   dout_57=dout_54|dout_55;
   dout_58=dout_36^dout_46;
   dout_59=dout_36&dout_46;
   dout_60=dout_58&dout_33;
   dout_61=dout_58^dout_33;
   dout_62=dout_59|dout_60;
   dout_63=dout_38^dout_47;
   dout_64=dout_38&dout_47;
   dout_65=dout_63&dout_35;
   dout_66=dout_63^dout_35;
   dout_67=dout_64|dout_65;
   dout_68=dout_40^dout_48;
   dout_69=dout_40&dout_48;
   dout_70=dout_68&dout_37;
   dout_71=dout_68^dout_37;
   dout_72=dout_69|dout_70;
   dout_73=dout_42^dout_49;
   dout_74=dout_42&dout_49;
   dout_75=dout_73&dout_39;
   dout_76=dout_73^dout_39;
   dout_77=dout_74|dout_75;
   dout_78=dout_44^dout_50;
   dout_79=dout_44&dout_50;
   dout_80=dout_78&dout_41;
   dout_81=dout_78^dout_41;
   dout_82=dout_79|dout_80;
   dout_83=dout_30^dout_51;
   dout_84=dout_30&dout_51;
   dout_85=((A >> 6)&1)&dout_43;
   dout_86=dout_83^dout_43;
   dout_87=dout_84|dout_85;
   dout_88=((A >> 0)&1)&((B >> 3)&1);
   dout_89=((A >> 1)&1)&((B >> 3)&1);
   dout_90=((A >> 2)&1)&((B >> 3)&1);
   dout_91=((A >> 3)&1)&((B >> 3)&1);
   dout_92=((A >> 4)&1)&((B >> 3)&1);
   dout_93=((A >> 5)&1)&((B >> 3)&1);
   dout_94=((A >> 6)&1)&((B >> 3)&1);
   dout_95=((A >> 7)&1)&((B >> 3)&1);
   dout_96=dout_61^dout_88;
   dout_97=dout_61&dout_88;
   dout_98=dout_96&dout_57;
   dout_99=dout_96^dout_57;
   dout_100=dout_97|dout_98;
   dout_101=dout_66^dout_89;
   dout_102=dout_66&dout_89;
   dout_103=dout_101&dout_62;
   dout_104=dout_101^dout_62;
   dout_105=dout_102|dout_103;
   dout_106=dout_71^dout_90;
   dout_107=dout_71&dout_90;
   dout_108=dout_106&dout_67;
   dout_109=dout_106^dout_67;
   dout_110=dout_107|dout_108;
   dout_111=dout_76^dout_91;
   dout_112=dout_76&dout_91;
   dout_113=dout_111&dout_72;
   dout_114=dout_111^dout_72;
   dout_115=dout_112|dout_113;
   dout_116=dout_81^dout_92;
   dout_117=dout_81&dout_92;
   dout_118=dout_116&dout_77;
   dout_119=dout_116^dout_77;
   dout_120=dout_117|dout_118;
   dout_121=dout_86^dout_93;
   dout_122=dout_86&dout_93;
   dout_123=dout_121&dout_82;
   dout_124=dout_121^dout_82;
   dout_125=dout_122|dout_123;
   dout_126=dout_52^dout_94;
   dout_127=dout_52&dout_94;
   dout_128=dout_126&dout_87;
   dout_129=dout_126^dout_87;
   dout_130=dout_127|dout_128;
   dout_131=((A >> 0)&1)&((B >> 4)&1);
   dout_132=((A >> 1)&1)&((B >> 4)&1);
   dout_133=((A >> 2)&1)&((B >> 4)&1);
   dout_134=((A >> 3)&1)&((B >> 4)&1);
   dout_135=((A >> 4)&1)&((B >> 4)&1);
   dout_136=((A >> 5)&1)&((B >> 4)&1);
   dout_137=((A >> 6)&1)&((B >> 4)&1);
   dout_138=((A >> 7)&1)&((B >> 4)&1);
   dout_139=dout_104^dout_131;
   dout_140=dout_104&dout_131;
   dout_141=dout_139&dout_100;
   dout_142=dout_139^dout_100;
   dout_143=dout_140|dout_141;
   dout_144=dout_109^dout_132;
   dout_145=dout_109&dout_132;
   dout_146=dout_144&dout_105;
   dout_147=dout_144^dout_105;
   dout_148=dout_145|dout_146;
   dout_149=dout_114^dout_133;
   dout_150=dout_114&dout_133;
   dout_151=dout_149&dout_110;
   dout_152=dout_149^dout_110;
   dout_153=dout_150|dout_151;
   dout_154=dout_119^dout_134;
   dout_155=dout_119&dout_134;
   dout_156=dout_154&dout_115;
   dout_157=dout_154^dout_115;
   dout_158=dout_155|dout_156;
   dout_159=dout_124^dout_135;
   dout_160=dout_124&dout_135;
   dout_161=dout_159&dout_120;
   dout_162=dout_159^dout_120;
   dout_163=dout_160|dout_161;
   dout_164=dout_129^dout_136;
   dout_165=dout_129&dout_136;
   dout_166=dout_164&dout_125;
   dout_167=dout_164^dout_125;
   dout_168=dout_165|dout_166;
   dout_169=dout_95^dout_137;
   dout_170=dout_95&dout_137;
   dout_171=dout_169&dout_130;
   dout_172=dout_169^dout_130;
   dout_173=dout_170|dout_171;
   dout_174=((A >> 0)&1)&((B >> 5)&1);
   dout_175=((A >> 1)&1)&((B >> 5)&1);
   dout_176=((A >> 2)&1)&((B >> 5)&1);
   dout_177=((A >> 3)&1)&((B >> 5)&1);
   dout_178=((A >> 4)&1)&((B >> 5)&1);
   dout_179=((A >> 5)&1)&((B >> 5)&1);
   dout_180=((A >> 6)&1)&((B >> 5)&1);
   dout_181=((A >> 7)&1)&((B >> 5)&1);
   dout_182=dout_147^dout_174;
   dout_183=dout_147&dout_174;
   dout_184=dout_182&dout_143;
   dout_185=dout_182^dout_143;
   dout_186=dout_183|dout_184;
   dout_187=dout_152^dout_175;
   dout_188=dout_152&dout_175;
   dout_189=dout_187&dout_148;
   dout_190=dout_187^dout_148;
   dout_191=dout_188|dout_189;
   dout_192=dout_157^dout_176;
   dout_193=dout_157&dout_176;
   dout_194=dout_192&dout_153;
   dout_195=dout_192^dout_153;
   dout_196=dout_193|dout_194;
   dout_197=dout_162^dout_177;
   dout_198=dout_162&dout_177;
   dout_199=dout_197&dout_158;
   dout_200=dout_197^dout_158;
   dout_201=dout_198|dout_199;
   dout_202=dout_167^dout_178;
   dout_203=dout_167&dout_178;
   dout_204=dout_202&dout_163;
   dout_205=dout_202^dout_163;
   dout_206=dout_203|dout_204;
   dout_207=dout_172^dout_179;
   dout_208=dout_172&dout_179;
   dout_209=dout_207&dout_168;
   dout_210=dout_207^dout_168;
   dout_211=dout_208|dout_209;
   dout_212=dout_138^dout_180;
   dout_213=dout_138&dout_180;
   dout_214=dout_212&dout_173;
   dout_215=dout_212^dout_173;
   dout_216=dout_213|dout_214;
   dout_217=((A >> 0)&1)&((B >> 6)&1);
   dout_218=((A >> 1)&1)&((B >> 6)&1);
   dout_219=((A >> 2)&1)&((B >> 6)&1);
   dout_220=((A >> 3)&1)&((B >> 6)&1);
   dout_221=((A >> 4)&1)&((B >> 6)&1);
   dout_222=((A >> 5)&1)&((B >> 6)&1);
   dout_223=((A >> 6)&1)&((B >> 6)&1);
   dout_224=((A >> 7)&1)&((B >> 6)&1);
   dout_225=dout_190^dout_217;
   dout_226=dout_190&dout_217;
   dout_227=dout_225&dout_186;
   dout_228=dout_225^dout_186;
   dout_229=dout_226|dout_227;
   dout_230=dout_195^dout_218;
   dout_231=dout_195&dout_218;
   dout_232=dout_230&dout_191;
   dout_233=dout_230^dout_191;
   dout_234=dout_231|dout_232;
   dout_235=dout_200^dout_219;
   dout_236=dout_200&dout_219;
   dout_237=dout_235&dout_196;
   dout_238=dout_235^dout_196;
   dout_239=dout_236|dout_237;
   dout_240=dout_205^dout_220;
   dout_241=dout_205&dout_220;
   dout_242=dout_240&dout_201;
   dout_243=dout_240^dout_201;
   dout_244=dout_241|dout_242;
   dout_245=dout_210^dout_221;
   dout_246=dout_210&dout_221;
   dout_247=dout_245&dout_206;
   dout_248=dout_245^dout_206;
   dout_249=dout_246|dout_247;
   dout_250=dout_215^dout_222;
   dout_251=dout_215&dout_222;
   dout_252=dout_250&dout_211;
   dout_253=dout_250^dout_211;
   dout_254=dout_251|dout_252;
   dout_255=dout_181^dout_223;
   dout_256=dout_181&dout_223;
   dout_257=dout_255&dout_216;
   dout_258=dout_255^dout_216;
   dout_259=dout_256|dout_257;
   dout_260=dout_233&dout_229;
   dout_261=dout_233^dout_229;
   dout_262=dout_238&dout_234;
   dout_263=dout_238^dout_234;
   dout_264=dout_243&dout_239;
   dout_265=dout_243^dout_239;
   dout_266=dout_248&dout_244;
   dout_267=dout_248^dout_244;
   dout_268=dout_253&dout_249;
   dout_269=dout_253^dout_249;
   dout_270=dout_258&dout_254;
   dout_271=dout_258^dout_254;
   dout_272=dout_224&dout_259;
   dout_273=dout_224^dout_259;
   dout_274=dout_263^dout_260;
   dout_275=dout_263&dout_260;
   dout_276=dout_265^dout_262;
   dout_277=dout_265&dout_262;
   dout_278=dout_276&dout_275;
   dout_279=dout_276^dout_275;
   dout_280=dout_277|dout_278;
   dout_281=dout_267^dout_264;
   dout_282=dout_267&dout_264;
   dout_283=dout_281&dout_280;
   dout_284=dout_281^dout_280;
   dout_285=dout_282|dout_283;
   dout_286=dout_269^dout_266;
   dout_287=dout_269&dout_266;
   dout_288=dout_286&dout_285;
   dout_289=dout_286^dout_285;
   dout_290=dout_287|dout_288;
   dout_291=dout_271^dout_268;
   dout_292=dout_271&dout_268;
   dout_293=dout_273^dout_270;
   dout_294=dout_273&dout_270;
   dout_295=dout_273&dout_292;
   dout_296=dout_293^dout_292;
   dout_297=dout_294|dout_295;
   dout_298=dout_272^dout_297;
   dout_301=dout_271^0xFFFFFFFFFFFFFFFFU;
   dout_302=dout_292|dout_271;
   dout_303=dout_273^dout_270;
   dout_305=dout_273&dout_302;
   dout_306=dout_303^dout_302;
   dout_308=dout_272|dout_305;
   dout_309=dout_290^0xFFFFFFFFFFFFFFFFU;
   dout_310=dout_291&dout_309;
   dout_311=dout_301&dout_290;
   dout_312=dout_310|dout_311;
   dout_313=dout_290^0xFFFFFFFFFFFFFFFFU;
   dout_314=dout_296&dout_313;
   dout_315=dout_306&dout_290;
   dout_316=dout_314|dout_315;
   dout_319=dout_308&dout_290;
   dout_320=dout_298|dout_319;

   O = 0;
   O |= (dout_31&1) << 0;
   O |= (dout_32&1) << 1;
   O |= (dout_56&1) << 2;
   O |= (dout_99&1) << 3;
   O |= (dout_142&1) << 4;
   O |= (dout_185&1) << 5;
   O |= (dout_228&1) << 6;
   O |= (dout_261&1) << 7;
   O |= (dout_274&1) << 8;
   O |= (dout_279&1) << 9;
   O |= (dout_284&1) << 10;
   O |= (dout_289&1) << 11;
   O |= (dout_312&1) << 12;
   O |= (dout_316&1) << 13;
   O |= (dout_320&1) << 14;
   return O;
}
