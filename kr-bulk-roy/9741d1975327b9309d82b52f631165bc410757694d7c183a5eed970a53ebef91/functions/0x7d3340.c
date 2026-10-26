
undefined4 FUN_007d3340(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  undefined4 uVar3;
  uint in_ECX;
  undefined1 local_88 [44];
  undefined1 local_5c [44];
  undefined1 local_30 [44];
  
  if ((uint)(*(int *)(in_EAX + 0x68) - *(int *)(in_EAX + 100) >> 2) < in_ECX) {
    return 0;
  }
  piVar1 = *(int **)(*(int *)(in_EAX + 100) + in_ECX * 4);
  if ((int *)*piVar1 != (int *)0x0) {
    piVar2 = (int *)piVar1[1];
    uVar3 = (**(code **)(*(int *)*piVar1 + 0x24))(local_88);
    uVar3 = (**(code **)(*piVar2 + 0x24))(local_5c,uVar3);
    FUN_0077e910(local_30,uVar3);
    FUN_0077ea00();
    return 1;
  }
  (**(code **)(*(int *)piVar1[1] + 0x24))(local_30);
  FUN_0077ea00();
  return 1;
}

