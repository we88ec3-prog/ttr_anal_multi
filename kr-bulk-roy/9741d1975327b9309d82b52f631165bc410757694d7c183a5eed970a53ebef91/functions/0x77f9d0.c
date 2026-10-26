
void FUN_0077f9d0(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *in_EAX;
  int iVar3;
  int *in_ECX;
  
  for (; in_ECX != param_1; in_ECX = in_ECX + 1) {
    puVar1 = (undefined4 *)*in_EAX;
    if (puVar1 != (undefined4 *)*in_ECX) {
      if (puVar1 != (undefined4 *)0x0) {
        piVar2 = puVar1 + 1;
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          (**(code **)*puVar1)(1);
        }
      }
      piVar2 = (int *)*in_ECX;
      *in_EAX = (int)piVar2;
      if (piVar2 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar2 + 8))();
        if (iVar3 == 0) {
          iVar3 = (**(code **)(*(int *)*in_EAX + 0xc))();
          *in_EAX = iVar3;
        }
        *(int *)(*in_EAX + 4) = *(int *)(*in_EAX + 4) + 1;
      }
    }
    in_EAX = in_EAX + 1;
  }
  return;
}

