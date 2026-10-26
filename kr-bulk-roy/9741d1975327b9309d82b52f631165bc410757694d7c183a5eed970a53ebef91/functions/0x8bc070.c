
void FUN_008bc070(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  
  iVar1 = in_EAX[1];
  iVar2 = in_EAX[2];
  iVar3 = *in_EAX;
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0xa0) == in_EAX)) {
    *(undefined4 *)(iVar1 + 0xa0) = 0;
  }
  if ((*(byte *)*in_EAX & 2) != 0) {
    FUN_008ba7e0();
  }
  if ((*(byte *)*in_EAX & 1) != 0) {
    FUN_008bb740();
  }
  if (*(code **)(iVar3 + 0x1c) != (code *)0x0) {
    (**(code **)(iVar3 + 0x1c))();
  }
  FUN_008b9f80(iVar2);
  return;
}

