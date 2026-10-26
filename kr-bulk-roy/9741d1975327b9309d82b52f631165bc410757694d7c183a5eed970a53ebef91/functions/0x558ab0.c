
/* WARNING: Removing unreachable block (ram,0x00558b5c) */

void FUN_00558ab0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 ***pppuVar3;
  int *piVar4;
  undefined4 local_68;
  uint local_54;
  undefined4 **local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_00922088;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
  local_8 = 0;
  iVar1 = FUN_00714550("Image/Splash/Splash.tga",local_14);
  if (iVar1 == 0) {
    FUN_00402a70("Image/Splash/Splash.tga",0x17);
    local_8._0_1_ = 1;
    uVar2 = FUN_00714aa0();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00402bb0(uVar2);
    if (0xf < local_54) {
      FUN_0089120c(local_68);
    }
    local_8 = local_8 & 0xffffff00;
  }
  else {
    FUN_00402a70("Image/Splash/Splash.tga",0x17);
  }
  pppuVar3 = (undefined4 ***)local_30[0];
  if (local_1c < 0x10) {
    pppuVar3 = local_30;
  }
  piVar4 = (int *)FUN_00714770(pppuVar3,&DAT_00bed1e0);
  if (piVar4 == (int *)0x0) {
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  else {
    (**(code **)(*piVar4 + 0x2c))();
    uVar2 = (**(code **)(*piVar4 + 0x38))();
    FUN_005588b0(uVar2);
    (**(code **)(*piVar4 + 4))();
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

