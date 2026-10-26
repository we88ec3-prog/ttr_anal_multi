
void FUN_0057f750(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *unaff_ESI;
  undefined4 *puVar3;
  
  if ((unaff_ESI[0x1f] == 0) && (unaff_ESI[0x1e] != 0)) {
    unaff_ESI[0x1e] = 0;
    if ((undefined4 *)unaff_ESI[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)unaff_ESI[5])(1);
      unaff_ESI[5] = 0;
    }
    if ((undefined4 *)unaff_ESI[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)unaff_ESI[4])(1);
      unaff_ESI[4] = 0;
    }
    puVar1 = (undefined4 *)unaff_ESI[0xe];
    for (puVar3 = (undefined4 *)unaff_ESI[0xd]; puVar3 != puVar1; puVar3 = puVar3 + 1) {
      (**(code **)(*(int *)*puVar3 + 4))();
    }
    piVar2 = (int *)*unaff_ESI;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *unaff_ESI = 0;
    }
    unaff_ESI[1] = 0;
  }
  return;
}

