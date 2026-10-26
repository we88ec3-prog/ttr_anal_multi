
undefined4 * FUN_005300f0(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int local_c;
  undefined1 local_8 [4];
  
  if ((*(int *)(in_EAX + 0x30) != 0) && (*(int *)(*(int *)(in_EAX + 0x30) + 4) != in_ECX)) {
    *(undefined4 *)(in_EAX + 0x30) = 0;
  }
  if (*(int *)(in_EAX + 0x30) == 0) {
    FUN_008438c0(local_8);
    if (local_c == *(int *)(in_EAX + 4)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(local_c + 0x10);
    }
    *(undefined4 *)(in_EAX + 0x30) = uVar2;
  }
  iVar1 = *(int *)(in_EAX + 0x30);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)(iVar1 + 8);
    if (7 < *(uint *)(iVar1 + 0x1c)) {
      return (undefined4 *)*puVar3;
    }
  }
  return puVar3;
}

