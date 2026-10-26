
void FUN_008440c0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_EAX;
  
  puVar2 = *(undefined4 **)(in_EAX + 4);
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  return;
}

