
int FUN_008f9380(int *param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  if (in_EAX == 0) {
    return 6;
  }
  iVar1 = *(int *)(in_EAX + 0x74);
  if (iVar1 == 0) {
    iVar2 = FUN_008f8120(param_2);
    if (iVar2 != 0) {
      return iVar2;
    }
    *(undefined4 *)(in_EAX + 0x74) = 0;
    *(code **)(in_EAX + 0x78) = FUN_008f3f40;
  }
  *param_1 = iVar1;
  return 0;
}

