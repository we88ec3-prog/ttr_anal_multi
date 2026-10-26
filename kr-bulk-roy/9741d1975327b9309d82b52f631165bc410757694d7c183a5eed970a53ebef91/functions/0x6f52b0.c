
void FUN_006f52b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  
  puVar2 = (undefined4 *)FUN_006f50f0();
  puVar3 = *(undefined4 **)(unaff_ESI + 8);
  puVar1 = puVar3;
  for (; puVar2 < puVar3; puVar3 = puVar3 + -4) {
    *puVar3 = puVar1[-4];
    puVar3[1] = puVar1[-3];
    puVar1[2] = puVar1[-2];
    puVar1 = puVar1 + -4;
  }
  puVar3 = *(undefined4 **)(unaff_ESI + 8);
  *puVar2 = *puVar3;
  puVar2[1] = puVar3[1];
  puVar2[2] = puVar3[2];
  return;
}

