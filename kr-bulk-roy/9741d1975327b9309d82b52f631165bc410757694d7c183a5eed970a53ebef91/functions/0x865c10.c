
void FUN_00865c10(void)

{
  int *piVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 local_8;
  
  if (*(int *)(in_EAX + 0x30) != *(int *)(in_EAX + 0x34)) {
    uVar2 = FUN_008666e0(*(int *)(in_EAX + 0x34),*(int *)(in_EAX + 0x30));
    FUN_00842540(uVar2,*(undefined4 *)(in_EAX + 0x34),local_8);
    *(undefined4 *)(in_EAX + 0x34) = uVar2;
  }
  if (*(int *)(in_EAX + 0x58) != 0) {
    FUN_008665e0(*(int *)(in_EAX + 0x58));
    piVar1 = *(int **)(in_EAX + 0x58);
    if (piVar1 != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    }
  }
  if (*(int *)(in_EAX + 0x5c) != 0) {
    FUN_00866660(*(int *)(in_EAX + 0x5c));
    piVar1 = *(int **)(in_EAX + 0x5c);
    if (piVar1 != (int *)0x0) {
      (*(code *)**(undefined4 **)(*(int *)(*piVar1 + 4) + (int)piVar1))(1);
    }
  }
  return;
}

