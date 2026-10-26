
void FUN_00797ec0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int unaff_EDI;
  undefined4 local_4c [4];
  undefined4 local_3c;
  undefined4 local_2c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009326de;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_0077f030(0,0,*(undefined4 *)(unaff_EDI + 0x24));
  uVar1 = *(undefined4 *)(unaff_EDI + 0x20);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x1c);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x18);
  _memset(local_4c,0,0x34);
  local_2c = 0x3f800000;
  local_3c = 0x3f800000;
  local_4c[0] = 0x3f800000;
  FUN_00790dc0(uVar3);
  FUN_00790e90(uVar2);
  FUN_00790f60(uVar1);
  FUN_00780890();
  FUN_0077efc0();
  fVar4 = *(float *)(unaff_EDI + 0x28);
  fVar5 = *(float *)(unaff_EDI + 0x14);
  uVar1 = *(undefined4 *)(unaff_EDI + 0x10);
  iVar6 = *(int *)(unaff_EDI + 8);
  *(undefined4 *)(iVar6 + 0x68) = *(undefined4 *)(unaff_EDI + 0xc);
  *(undefined4 *)(iVar6 + 0x6c) = uVar1;
  *(float *)(iVar6 + 0x70) = fVar5 + fVar4;
  *(undefined4 *)(iVar6 + 0xc0) = 0;
  FUN_00780150(*(int *)(unaff_EDI + 8),*(undefined4 *)(*(int *)(unaff_EDI + 8) + 0x30));
  *(undefined4 *)(unaff_EDI + 0xd4) = *(undefined4 *)(unaff_EDI + 0x24);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  (**(code **)(**(int **)(unaff_EDI + 8) + 0x28))(DAT_00fb76a8);
  ExceptionList = pvStack_18;
  return;
}

