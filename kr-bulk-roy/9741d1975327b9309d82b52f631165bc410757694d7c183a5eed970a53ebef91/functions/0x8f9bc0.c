
int FUN_008f9bc0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = (**(code **)(unaff_EBX + 0x20))(*(undefined4 *)(unaff_EBX + 0x28),0x13,4);
  if (iVar1 == 0) {
    return -4;
  }
  iVar2 = FUN_008f9680(param_1,0x13,0x13,0,0,param_2,&local_8,iVar1);
  if (iVar2 == -3) {
    *(char **)(unaff_EBX + 0x18) = "oversubscribed dynamic bit lengths tree";
  }
  else if ((iVar2 == -5) || (*param_2 == 0)) {
    *(char **)(unaff_EBX + 0x18) = "incomplete dynamic bit lengths tree";
    iVar2 = -3;
  }
  (**(code **)(unaff_EBX + 0x24))(*(undefined4 *)(unaff_EBX + 0x28),iVar1);
  return iVar2;
}

