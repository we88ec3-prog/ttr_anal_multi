
int * FUN_0077b030(void)

{
  code *pcVar1;
  void *pvVar2;
  int *piVar3;
  int in_ECX;
  
  pvVar2 = _malloc(0x54);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0077b150();
  }
  (**(code **)(*piVar3 + 0x34))();
  piVar3[1] = *(int *)(in_ECX + 4);
  piVar3[2] = *(int *)(in_ECX + 8);
  FUN_00776790(in_ECX + 0xc);
  *(undefined1 *)(piVar3 + 0x13) = *(undefined1 *)(in_ECX + 0x4c);
  pcVar1 = *(code **)(*piVar3 + 0x38);
  *(undefined1 *)((int)piVar3 + 0x4d) = *(undefined1 *)(in_ECX + 0x4d);
  piVar3[0x14] = *(int *)(in_ECX + 0x50);
  (*pcVar1)();
  return piVar3;
}

