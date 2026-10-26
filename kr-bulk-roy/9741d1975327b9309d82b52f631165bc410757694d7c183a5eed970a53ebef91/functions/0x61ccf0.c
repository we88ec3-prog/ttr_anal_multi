
void FUN_0061ccf0(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 extraout_CL;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar2 = param_1;
  puStack_c = &LAB_009430de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  iVar6 = param_2;
  local_8 = 0xffffffff;
  param_1 = param_2;
  FUN_0082ef00(&param_1);
  if ((local_18 != DAT_00fb11b0) && (iVar1 = *(int *)(local_18 + 0x10), iVar1 != 0)) {
    FUN_0082ef00(&param_2);
    if (param_1 == *(int *)(iVar2 + 0xf8)) {
      uVar4 = (param_3 & 0xff) + 1;
      cVar3 = FUN_0061d1e0(iVar2,iVar6,uVar4);
      param_1 = CONCAT13(cVar3,(undefined3)param_1);
      if (*(int *)(iVar1 + 0x14) == *(int *)(iVar1 + 0x18)) {
        ExceptionList = local_10;
        return;
      }
      if ((byte)((char)(*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2) - 1U) <= (byte)param_3
         ) {
        ExceptionList = local_10;
        return;
      }
      if (cVar3 == '\0') {
        ExceptionList = local_10;
        return;
      }
      if ((*(uint *)(*(int *)(iVar2 + ((param_4 + 0x10) * 7 + param_5) * 4) + 0x28) >> 7 & 1) == 0)
      {
        ExceptionList = local_10;
        return;
      }
      param_3 = FUN_0081aea0();
      uVar7 = FUN_006d49c0();
      FUN_0082f200(iVar2 + 0xf4,uVar7);
      FUN_00616790();
      FUN_0061d120(*(undefined4 *)(param_3 + 4));
    }
    else {
      uVar4 = *(byte *)(param_1 + 0x10) + 1;
      cVar3 = FUN_0061d1e0(iVar2,iVar6,uVar4);
      param_3 = CONCAT13(cVar3,(undefined3)param_3);
      if (*(int *)(iVar1 + 0x14) == *(int *)(iVar1 + 0x18)) {
        uVar5 = 0;
      }
      else {
        uVar5 = (*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2) - 1;
      }
      if ((uVar5 & 0xff) < uVar4) {
        ExceptionList = local_10;
        return;
      }
      if (cVar3 == '\0') {
        ExceptionList = local_10;
        return;
      }
      if ((*(uint *)(*(int *)(iVar2 + ((param_4 + 0x10) * 7 + param_5) * 4) + 0x28) >> 7 & 1) == 0)
      {
        ExceptionList = local_10;
        return;
      }
      iVar6 = FUN_0081aea0();
      *(undefined1 *)(param_1 + 0x10) = extraout_CL;
      FUN_00616790();
      FUN_0061d120(*(undefined4 *)(iVar6 + 4));
    }
    FUN_0061cac0(param_2,uVar4,param_5,1);
    FUN_0061d540(iVar2);
  }
  ExceptionList = local_10;
  return;
}

