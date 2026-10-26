
void FUN_007d9910(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int *in_ECX;
  float10 fVar4;
  undefined1 auStack_324 [12];
  undefined4 uStack_318;
  undefined1 *puStack_314;
  undefined1 *puStack_310;
  undefined8 uStack_30c;
  uint uStack_304;
  undefined1 auStack_2f4 [56];
  undefined4 *local_2bc;
  undefined1 *local_2b8;
  uint uStack_2b4;
  undefined4 uStack_2a4;
  uint uStack_2a0;
  uint auStack_298 [4];
  undefined4 uStack_288;
  uint uStack_284;
  uint auStack_27c [4];
  undefined4 uStack_26c;
  uint uStack_268;
  undefined1 local_260 [152];
  undefined1 auStack_1c8 [64];
  undefined1 auStack_188 [260];
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  uint local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_0091c8a2;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_2f4;
  uStack_304 = DAT_00d61f20 ^ (uint)&stack0xfffffd00;
  ExceptionList = &local_4c;
  uStack_30c = (double)CONCAT44("Animation",local_260);
  local_2bc = (undefined4 *)param_1;
  local_2b8 = (undefined1 *)param_2;
  puStack_310 = (undefined1 *)0x7d9972;
  FUN_0072e420();
  local_44 = 0;
  uStack_30c = (double)CONCAT44(0x7d9984,(undefined4)uStack_30c);
  uVar1 = (**(code **)(*in_ECX + 8))();
  puStack_310 = auStack_1c8;
  uStack_30c = (double)CONCAT44(uVar1,&DAT_00c0d6dc);
  puStack_314 = (undefined1 *)0x7d999a;
  FUN_00730d80();
  uStack_30c = (double)CONCAT44(&DAT_00bfb82c,local_260);
  puStack_310 = (undefined1 *)0x7d99b6;
  FUN_0072e770();
  uStack_30c = 8.49422706865636e-314;
  uStack_268 = 0xf;
  uStack_26c = 0;
  auStack_27c[0] = auStack_27c[0] & 0xffffff00;
  puStack_310 = (undefined1 *)0x7d99e2;
  FUN_00402a70();
  local_44._0_1_ = 1;
  uStack_30c = (double)CONCAT44(in_ECX,0x7d99f4);
  uVar1 = FUN_007d8c70();
  uStack_30c = (double)CONCAT44(uVar1,auStack_27c);
  local_44 = CONCAT31(local_44._1_3_,2);
  puStack_310 = (undefined1 *)0x7d9a11;
  FUN_0072e890();
  if (0xf < uStack_2a0) {
    uStack_30c = (double)CONCAT44(uStack_2b4,0x7d9a26);
    FUN_0089120c();
  }
  local_44 = local_44 & 0xffffff00;
  uStack_2a0 = 0xf;
  uStack_2a4 = 0;
  uStack_2b4 = uStack_2b4 & 0xffffff00;
  if (0xf < uStack_268) {
    uStack_30c = (double)CONCAT44(auStack_27c[0],0x7d9a56);
    FUN_0089120c();
  }
  uStack_30c = (double)CONCAT44(0x7d9a62,(undefined4)uStack_30c);
  iVar2 = (**(code **)(*in_ECX + 0x40))();
  pcVar3 = "true";
  if (*(char *)(iVar2 + 0x20) == '\0') {
    pcVar3 = "false";
  }
  puStack_310 = auStack_1c8;
  uStack_30c = (double)CONCAT44(pcVar3,&DAT_00bfc638);
  puStack_314 = (undefined1 *)0x7d9a8e;
  FUN_00730d80();
  uStack_30c = (double)CONCAT44("CameraAttach",local_260);
  puStack_310 = (undefined1 *)0x7d9aaa;
  FUN_0072e770();
  uStack_30c = 0.0;
  puStack_314 = auStack_188;
  puStack_310 = &DAT_00c420d8;
  uStack_318 = 0x7d9ac9;
  FUN_00730da0();
  uStack_30c = (double)CONCAT44("FrameSpeed",local_260);
  puStack_310 = (undefined1 *)0x7d9ae5;
  FUN_0072e770();
  uStack_30c = (double)CONCAT44(0x7d9aee,(undefined4)uStack_30c);
  iVar2 = (**(code **)(*in_ECX + 0x40))();
  puStack_310 = auStack_1c8;
  uStack_30c = (double)(ulonglong)CONCAT14(*(undefined1 *)(iVar2 + 0x29),&DAT_00c0d6dc);
  puStack_314 = (undefined1 *)0x7d9b0a;
  FUN_00730d80();
  uStack_30c = (double)CONCAT44("FaceIndex",local_260);
  puStack_310 = (undefined1 *)0x7d9b26;
  FUN_0072e770();
  uStack_30c = (double)CONCAT44(0x7d9b2f,(undefined4)uStack_30c);
  iVar2 = (**(code **)(*in_ECX + 0x40))();
  pcVar3 = "true";
  if (*(char *)(iVar2 + 0x21) == '\0') {
    pcVar3 = "false";
  }
  puStack_310 = auStack_1c8;
  uStack_30c = (double)CONCAT44(pcVar3,&DAT_00bfc638);
  puStack_314 = (undefined1 *)0x7d9b5b;
  FUN_00730d80();
  uStack_30c = (double)CONCAT44("Repeat",local_260);
  puStack_310 = (undefined1 *)0x7d9b77;
  FUN_0072e770();
  uStack_30c = (double)CONCAT44(0x7d9b80,(undefined4)uStack_30c);
  fVar4 = (float10)(**(code **)(*in_ECX + 0x18))();
  uStack_30c = (double)fVar4;
  puStack_314 = auStack_188;
  puStack_310 = &DAT_00c420d8;
  uStack_318 = 0x7d9b9d;
  FUN_00730da0();
  uStack_30c = (double)CONCAT44("RepeatStartFrame",local_260);
  puStack_310 = (undefined1 *)0x7d9bb9;
  FUN_0072e770();
  uStack_30c = (double)CONCAT44(0x7d9bc2,(undefined4)uStack_30c);
  iVar2 = (**(code **)(*in_ECX + 0x40))();
  puStack_310 = auStack_1c8;
  uStack_30c = (double)(ulonglong)CONCAT14(*(undefined1 *)(iVar2 + 0x28),&DAT_00c0d6dc);
  puStack_314 = (undefined1 *)0x7d9bde;
  FUN_00730d80();
  uStack_30c = (double)CONCAT44("LagtimeType",local_260);
  puStack_310 = (undefined1 *)0x7d9bfa;
  FUN_0072e770();
  uStack_30c = (double)CONCAT44(0x7d9c01,(undefined4)uStack_30c);
  fVar4 = (float10)FUN_007d9630();
  uStack_30c = (double)fVar4;
  puStack_314 = auStack_188;
  puStack_310 = &DAT_00c420d8;
  uStack_318 = 0x7d9c1e;
  FUN_00730da0();
  uStack_30c = (double)CONCAT44("Length",local_260);
  puStack_310 = (undefined1 *)0x7d9c3a;
  FUN_0072e770();
  uStack_30c = (double)CONCAT44(0x7d9c4a,(undefined4)uStack_30c);
  FUN_0072e1e0();
  uStack_30c = -NAN;
  puStack_310 = local_2b8;
  uStack_284 = 0xf;
  uStack_288 = 0;
  auStack_298[0] = auStack_298[0] & 0xffffff00;
  puStack_314 = (undefined1 *)0x7d9c72;
  FUN_00403040();
  uStack_30c = 8.49436160470799e-314;
  local_44._0_1_ = 3;
  puStack_310 = (undefined1 *)0x7d9c8a;
  FUN_00401fc0();
  uStack_30c = (double)((ulonglong)uStack_30c & 0xffffffff);
  local_2b8 = auStack_324;
  puStack_310 = (undefined1 *)0xf;
  puStack_314 = (undefined1 *)0x0;
  auStack_324[0] = 0;
  FUN_00403040(auStack_298,0,0xffffffff);
  local_44._0_1_ = 4;
  local_2bc = (undefined4 *)FUN_007d8c70(in_ECX);
  local_44._0_1_ = 5;
  if (0xf < (uint)local_2bc[5]) {
    local_2bc = (undefined4 *)*local_2bc;
  }
  (**(code **)(*in_ECX + 8))();
  local_44 = CONCAT31(local_44._1_3_,6);
  FUN_007d9d80(local_2bc);
  if (0xf < uStack_2a0) {
    uStack_30c = (double)CONCAT44(uStack_2b4,0x7d9d03);
    FUN_0089120c();
  }
  uStack_2a0 = 0xf;
  uStack_2a4 = 0;
  uStack_2b4 = uStack_2b4 & 0xffffff00;
  if (0xf < uStack_284) {
    uStack_30c = (double)CONCAT44(auStack_298[0],0x7d9d2a);
    FUN_0089120c();
  }
  uStack_284 = 0xf;
  uStack_288 = 0;
  auStack_298[0] = auStack_298[0] & 0xffffff00;
  local_44 = 0xffffffff;
  uStack_30c = (double)CONCAT44(0x7d9d53,(undefined4)uStack_30c);
  FUN_0072e520();
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_2f4);
  return;
}

