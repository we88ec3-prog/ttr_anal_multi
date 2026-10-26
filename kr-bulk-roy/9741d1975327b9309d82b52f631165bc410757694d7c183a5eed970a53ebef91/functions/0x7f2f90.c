
uint FUN_007f2f90(void)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b97e;
  local_10 = ExceptionList;
  puVar3 = *(undefined4 **)(in_ECX + 0x84);
  if (puVar3 == (undefined4 *)0x0) {
    return 1;
  }
  fVar1 = (float)puVar3[0x26];
  fVar2 = (float)puVar3[6];
  uVar4 = *puVar3;
  uVar5 = puVar3[1];
  uVar6 = puVar3[2];
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if (DAT_00fb76e4 == 0) {
    iVar7 = 1;
  }
  else {
    iVar7 = FUN_00838860(uVar4,uVar5,uVar6,fVar1 * fVar2);
  }
  *(uint *)(in_ECX + 0x80) = (uint)(iVar7 == 0);
  ExceptionList = local_10;
  return (uint)(iVar7 == 0);
}

