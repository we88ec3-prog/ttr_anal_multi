
void FUN_0049da60(int param_1)

{
  short sVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  short *psVar5;
  undefined4 uVar6;
  float *pfVar7;
  float10 fVar8;
  float fVar9;
  float fStack_3ac;
  wchar_t *pwStack_3a8;
  wchar_t *pwStack_3a4;
  undefined8 uStack_3a0;
  undefined8 uStack_398;
  undefined8 uStack_390;
  undefined1 auStack_374 [32];
  float *pfStack_354;
  float fStack_350;
  float *pfStack_34c;
  float fStack_348;
  float *pfStack_344;
  float fStack_340;
  undefined4 uStack_33c;
  undefined4 uStack_32c;
  uint uStack_328;
  float *pfStack_31c;
  int iStack_318;
  undefined4 uStack_314;
  float *pfStack_310;
  float fStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_2f8;
  uint uStack_2f4;
  uint auStack_2ec [4];
  undefined4 uStack_2dc;
  uint uStack_2d8;
  undefined1 auStack_2a0 [12];
  short sStack_294;
  undefined1 auStack_292 [522];
  uint uStack_88;
  uint local_84;
  void *pvStack_50;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  puStack_48 = &LAB_00930df6;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_374;
  ExceptionList = &local_4c;
  piVar2 = *(int **)(param_1 + 4);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_44 = 0;
    FUN_00798de0();
    uStack_390 = (double)CONCAT44(0x49dad0,(undefined4)uStack_390);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_44 = 0xffffffff;
  uStack_390 = (double)CONCAT44(0x49daef,(undefined4)uStack_390);
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x50))();
  if (DAT_00fb76e4 != 0) {
    uStack_390 = *(double *)(puVar3 + 1);
    uStack_398 = (double)CONCAT44(*puVar3,0x49db19);
    iVar4 = FUN_00838800();
    if (iVar4 == 0) goto switchD_0049db59_caseD_2;
  }
  uStack_2d8 = 7;
  uStack_2dc = 0;
  auStack_2ec[0] = auStack_2ec[0] & 0xffff0000;
  puStack_48 = (undefined1 *)0x1;
  switch((char)piVar2[1]) {
  case '\0':
  case '\x01':
    uStack_390 = (double)(ulonglong)
                         CONCAT14(*(char *)((int)piVar2 + 0x8a) + '\x01',
                                  (uint)*(ushort *)(piVar2 + 0x22));
    uStack_398 = 4.661060386953224e-305;
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49db9c);
    FUN_0041f490();
    uStack_390 = (double)CONCAT44(piVar2[0x24],(uint)*(ushort *)(piVar2 + 1));
    uStack_398 = 4.661268987627511e-305;
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49dbd0);
    FUN_00404420();
    pfStack_34c = (float *)piVar2[0x33];
    pfStack_354 = (float *)piVar2[0xe6];
    uStack_390 = (double)(float)pfStack_34c;
    uStack_398 = (double)(float)pfStack_354;
    uStack_3a0 = (double)CONCAT44(piVar2[0xe3],*(undefined4 *)(piVar2[0x56] + 8));
    pwStack_3a4 = L"[State: %d][Motion: %d %.2f B.Speed:%.2f ] \n";
    pwStack_3a8 = L"쒃贜⒄\x9c";
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49dc2f);
    FUN_00404420();
    if (piVar2 != (int *)0xfffffc10) {
      uStack_390 = 4.661825256092289e-305;
      FUN_00498ed0();
      uStack_390 = (double)CONCAT44(auStack_2ec,0x49dc65);
      FUN_00404420();
      pfVar7 = (float *)piVar2[0xfd];
      pfStack_34c = (float *)*pfVar7;
      while (pfStack_34c != pfVar7) {
        uStack_390 = (double)(CONCAT44((uint)pfStack_34c[4] >> 0x10,pfStack_34c[4]) & 0xff0000ffff);
        uStack_398 = 4.661894789650437e-305;
        FUN_00498ed0();
        psVar5 = &sStack_294;
        do {
          sVar1 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar1 != 0);
        uStack_390 = (double)CONCAT44((int)psVar5 - (int)auStack_292 >> 1,&sStack_294);
        uStack_398 = (double)CONCAT44(0x49dcc4,(undefined4)uStack_398);
        FUN_00404300();
        uStack_390 = (double)CONCAT44(0x49dccd,(undefined4)uStack_390);
        FUN_0049e6a0();
      }
      uStack_390 = 4.661964323208599e-305;
      FUN_00498ed0();
      psVar5 = &sStack_294;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      uStack_390 = (double)CONCAT44((int)psVar5 - (int)auStack_292 >> 1,&sStack_294);
      uStack_398 = (double)CONCAT44(0x49dd17,(undefined4)uStack_398);
      FUN_00404300();
    }
    uStack_390 = (double)CONCAT44(auStack_2a0,0x49dd2d);
    uStack_390._4_4_ = (float **)(**(code **)(*piVar2 + 0x50))();
    uStack_398 = (double)CONCAT44(0x49dd34,(undefined4)uStack_398);
    uVar6 = FUN_00434740();
    uStack_390 = (double)CONCAT44(uStack_390._4_4_,uVar6);
    uStack_398 = (double)CONCAT44(0x49dd44,(undefined4)uStack_398);
    pfVar7 = (float *)FUN_0079b910();
    pfStack_354 = (float *)*pfVar7;
    fStack_350 = pfVar7[1];
    uStack_2f4 = 7;
    uStack_2f8 = 0;
    uStack_308 = (uint)uStack_308._2_2_ << 0x10;
    puStack_48._0_1_ = 2;
    uStack_390 = -NAN;
    uStack_398 = (double)CONCAT44(auStack_2ec,0x49dda8);
    pfStack_310 = pfStack_354;
    fStack_30c = fStack_350;
    FUN_004026e0();
    pfStack_344 = pfStack_310;
    uStack_390 = -NAN;
    fStack_340 = fStack_30c;
    uStack_328 = 7;
    uStack_32c = 0;
    uStack_33c = (uint)uStack_33c._2_2_ << 0x10;
    uStack_398 = (double)CONCAT44(&uStack_308,0x49dddb);
    FUN_004026e0();
    puStack_48._0_1_ = 3;
    uStack_390 = (double)CONCAT44(0x49dde8,(undefined4)uStack_390);
    FUN_0040cf80();
    puStack_48 = (undefined1 *)CONCAT31(puStack_48._1_3_,4);
    uStack_390 = (double)CONCAT44(0x49ddfc,(undefined4)uStack_390);
    FUN_0049e530();
    if (7 < uStack_328) {
      uStack_390 = (double)CONCAT44(uStack_33c,0x49de11);
      FUN_0089120c();
    }
    uStack_328 = 7;
    uStack_32c = 0;
    uStack_33c = uStack_33c & 0xffff0000;
    if (7 < uStack_2f4) {
      uStack_390 = (double)CONCAT44(uStack_308,0x49de3d);
      FUN_0089120c();
    }
    goto LAB_0049e1ef;
  default:
    goto switchD_0049db59_caseD_2;
  case '\x03':
    pfStack_354 = (float *)piVar2[0x29];
    pfStack_34c = (float *)piVar2[0x28];
    uStack_398 = *(double *)(piVar2 + 0x28);
    uStack_390 = (double)ZEXT48(&uStack_314);
    uStack_314 = 0x477fff00;
    uStack_3a0 = (double)CONCAT44(0x49e11a,(undefined4)uStack_3a0);
    pfStack_31c = pfStack_34c;
    iStack_318 = (int)pfStack_354;
    (**(code **)*DAT_00fba838)();
    uStack_390._4_4_ = &pfStack_31c;
    uStack_398 = (double)CONCAT44(0x49e125,(undefined4)uStack_398);
    uVar6 = FUN_00434740();
    uStack_390 = (double)CONCAT44(uStack_390._4_4_,uVar6);
    uStack_398 = (double)CONCAT44(0x49e135,(undefined4)uStack_398);
    pfVar7 = (float *)FUN_0079b910();
    pfStack_354 = (float *)*pfVar7;
    uStack_390 = (double)(ulonglong)CONCAT24((short)piVar2[0x22],(uint)*(ushort *)(piVar2 + 1));
    fStack_350 = pfVar7[1];
    uStack_398 = 4.663633128603651e-305;
    FUN_00498ed0();
    uStack_2f4 = 7;
    uStack_2f8 = 0;
    uStack_308 = (uint)uStack_308._2_2_ << 0x10;
    puStack_48._0_1_ = 7;
    fStack_30c = fStack_350;
    pfStack_310 = pfStack_354;
    uStack_390 = (double)CONCAT44(&uStack_308,0x49e1b6);
    FUN_0041f490();
    pfStack_354 = &fStack_3ac;
    FUN_0049e260();
    puStack_48._0_1_ = 8;
    uVar6 = FUN_0040cf80();
    puStack_48 = (undefined1 *)CONCAT31(puStack_48._1_3_,7);
    break;
  case '\a':
    pfStack_354 = (float *)piVar2[0x29];
    pfStack_34c = (float *)piVar2[0x28];
    uStack_398 = *(double *)(piVar2 + 0x28);
    uStack_390 = (double)ZEXT48(&uStack_314);
    uStack_314 = 0x477fff00;
    uStack_3a0 = (double)CONCAT44(0x49dea6,(undefined4)uStack_3a0);
    pfStack_31c = pfStack_34c;
    iStack_318 = (int)pfStack_354;
    (**(code **)*DAT_00fba838)();
    uStack_390._4_4_ = &pfStack_31c;
    uStack_398 = (double)CONCAT44(0x49deb1,(undefined4)uStack_398);
    uVar6 = FUN_00434740();
    uStack_390 = (double)CONCAT44(uStack_390._4_4_,uVar6);
    uStack_398 = (double)CONCAT44(0x49dec1,(undefined4)uStack_398);
    pfVar7 = (float *)FUN_0079b910();
    pfStack_34c = (float *)*pfVar7;
    fVar9 = pfVar7[1];
    uStack_390 = (double)(ulonglong)CONCAT24((short)piVar2[0x22],(uint)*(ushort *)(piVar2 + 1));
    uStack_398 = 4.661999089988171e-305;
    fStack_348 = fVar9;
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49df0b);
    FUN_0041f490();
    pfStack_354 = (float *)piVar2[0x33];
    iVar4 = piVar2[0xe3];
    uStack_390 = (double)(float)pfStack_354;
    uStack_398 = (double)CONCAT44(0x49df2c,(undefined4)uStack_398);
    FUN_004c8d30();
    uStack_398 = (double)fVar9;
    uStack_3a0 = (double)CONCAT44(0x49df41,(undefined4)uStack_3a0);
    pfStack_354 = (float *)fVar9;
    FUN_004c8e30();
    uStack_3a0 = (double)fVar9;
    pwStack_3a8 = L"[MotionID : %d, Motion Length : %f, Frame : %f, Base Spd : %f]\n";
    fStack_3ac = 6.784127e-39;
    pwStack_3a4 = (wchar_t *)iVar4;
    pfStack_354 = (float *)fVar9;
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49df7a);
    FUN_00404420();
    uStack_390 = (double)CONCAT44(0x49df81,(undefined4)uStack_390);
    fVar8 = (float10)FUN_004c9a20();
    uStack_390 = (double)fVar8;
    uStack_398 = (double)CONCAT44(0x49df8e,(undefined4)uStack_398);
    FUN_004c8d50();
    uStack_398 = (double)fVar9;
    uStack_3a0 = (double)CONCAT44(0x49dfa5,(undefined4)uStack_3a0);
    pfStack_354 = (float *)fVar9;
    fVar8 = (float10)FUN_004c9ab0();
    uStack_3a0 = (double)fVar8;
    pwStack_3a4 = L"[FEP : %f, LastF: %f, RepeatSF : %f]\n";
    pwStack_3a8 = L"쒃贜⒄\x9c";
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49dfd3);
    FUN_00404420();
    pfStack_354 = (float *)piVar2[0x36];
    fStack_350 = (float)piVar2[0x37];
    uStack_390 = (double)(ulonglong)CONCAT14((char)piVar2[0xe9],(uint)*(byte *)(piVar2 + 0x2c));
    uStack_398 = (double)fStack_350;
    uStack_3a0 = (double)(float)pfStack_354;
    pwStack_3a4 = L"[delta.x : %f, delta.y : %f, dir: %f, lookdir : %f]\n";
    pwStack_3a8 = L"쒃贜⒔\x9c";
    FUN_00498ed0();
    uStack_390 = (double)CONCAT44(auStack_2ec,0x49e035);
    FUN_00404420();
    uStack_2f4 = 7;
    uStack_2f8 = 0;
    uStack_308 = (uint)uStack_308._2_2_ << 0x10;
    puStack_48._0_1_ = 5;
    uStack_390 = -NAN;
    pfStack_310 = pfStack_34c;
    fStack_30c = fStack_348;
    uStack_398 = (double)CONCAT44(auStack_2ec,0x49e08b);
    FUN_004026e0();
    pfStack_354 = &fStack_3ac;
    FUN_0049e260();
    puStack_48._0_1_ = 6;
    uVar6 = FUN_0040cf80();
    puStack_48 = (undefined1 *)CONCAT31(puStack_48._1_3_,5);
  }
  FUN_0049e4d0(uVar6);
  uStack_390 = (double)CONCAT44(0x49e1ef,(undefined4)uStack_390);
  FUN_0044b470();
LAB_0049e1ef:
  if (7 < uStack_2d8) {
    uStack_390 = (double)CONCAT44(auStack_2ec[0],0x49e206);
    FUN_0089120c();
  }
switchD_0049db59_caseD_2:
  ExceptionList = pvStack_50;
  __security_check_cookie(uStack_88 ^ (uint)&stack0xfffffc88);
  return;
}

