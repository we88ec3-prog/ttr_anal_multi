
int FUN_008b8b80(int param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  int local_8;
  
  local_8 = 0;
  if (param_1 == 0) {
    return 0x23;
  }
  if (param_5 == (uint *)0x0) {
    return 6;
  }
  iVar2 = *(int *)(param_1 + 0x60);
  *param_5 = 0;
  param_5[1] = 0;
  pcVar3 = *(code **)(*(int *)(iVar2 + 0xc) + 0x4c);
  if (pcVar3 != (code *)0x0) {
    local_8 = (*pcVar3)(param_1,param_2,param_3,param_5);
    if ((local_8 == 0) && (param_4 != 2)) {
      uVar4 = FUN_008b7f10(*param_5,*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x10));
      *param_5 = uVar4;
      uVar4 = FUN_008b7f10(param_5[1],*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x14));
      param_5[1] = uVar4;
      if (param_4 != 1) {
        uVar1 = *(ushort *)(*(int *)(param_1 + 0x58) + 0xc);
        if (uVar1 < 0x19) {
          uVar5 = FUN_008b7dc0(*param_5,uVar1,0x19);
          *param_5 = uVar5;
        }
        uVar1 = *(ushort *)(*(int *)(param_1 + 0x58) + 0xe);
        if (uVar1 < 0x19) {
          uVar4 = FUN_008b7dc0(uVar4,uVar1,0x19);
          param_5[1] = uVar4;
        }
        *param_5 = *param_5 + 0x20 & 0xffffffc0;
        param_5[1] = param_5[1] + 0x20 & 0xffffffc0;
      }
    }
  }
  return local_8;
}

