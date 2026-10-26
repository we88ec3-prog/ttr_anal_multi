
int FUN_008f9c50(uint param_1,undefined4 param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = (**(code **)(unaff_EBX + 0x20))(*(undefined4 *)(unaff_EBX + 0x28),0x120,4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar2 = FUN_008f9680(param_3,param_1,0x101,&DAT_00bebd38,&DAT_00bebdb8,param_4,&local_8,iVar1);
  if (iVar2 == 0) {
    if (*param_4 != 0) {
      iVar2 = FUN_008f9680(param_3 + param_1 * 4,param_2,0,&DAT_00bebe38,&DAT_00bebeb0,param_5,
                           &local_8,iVar1);
      if (iVar2 == 0) {
        if ((*param_5 != 0) || (param_1 < 0x102)) {
          (**(code **)(unaff_EBX + 0x24))(*(undefined4 *)(unaff_EBX + 0x28),iVar1);
          return 0;
        }
      }
      else {
        if (iVar2 == -3) {
          *(char **)(unaff_EBX + 0x18) = "oversubscribed distance tree";
          (**(code **)(unaff_EBX + 0x24))(*(undefined4 *)(unaff_EBX + 0x28),iVar1);
          return -3;
        }
        if (iVar2 == -5) {
          *(char **)(unaff_EBX + 0x18) = "incomplete distance tree";
          (**(code **)(unaff_EBX + 0x24))(*(undefined4 *)(unaff_EBX + 0x28),iVar1);
          return -3;
        }
        if (iVar2 == -4) goto LAB_008f9d74;
      }
      *(char **)(unaff_EBX + 0x18) = "empty distance tree with lengths";
      iVar2 = -3;
LAB_008f9d74:
      (**(code **)(unaff_EBX + 0x24))(*(undefined4 *)(unaff_EBX + 0x28),iVar1);
      return iVar2;
    }
  }
  else {
    if (iVar2 == -3) {
      *(char **)(unaff_EBX + 0x18) = "oversubscribed literal/length tree";
      goto LAB_008f9da8;
    }
    if (iVar2 == -4) goto LAB_008f9da8;
  }
  *(char **)(unaff_EBX + 0x18) = "incomplete literal/length tree";
  iVar2 = -3;
LAB_008f9da8:
  (**(code **)(unaff_EBX + 0x24))(*(undefined4 *)(unaff_EBX + 0x28),iVar1);
  return iVar2;
}

