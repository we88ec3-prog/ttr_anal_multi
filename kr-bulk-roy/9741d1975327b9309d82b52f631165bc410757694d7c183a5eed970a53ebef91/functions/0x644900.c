
void FUN_00644900(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a19c;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = unaff_EDI[4];
  iVar2 = unaff_EDI[5];
  iVar3 = unaff_EDI[2];
  iVar4 = unaff_EDI[3];
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(uVar5);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058ee60(&DAT_00faaf80);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 1;
    FUN_0058d410(uVar5);
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = 0xffffffff;
  }
  FUN_0058ee60(&DAT_00faaf80);
  (**(code **)(*unaff_EDI + 0xbc))
            (unaff_EDI[2],unaff_EDI[3],unaff_EDI[2] + (iVar1 - iVar3),(iVar2 - iVar4) + unaff_EDI[3]
            );
  ExceptionList = local_10;
  return;
}

