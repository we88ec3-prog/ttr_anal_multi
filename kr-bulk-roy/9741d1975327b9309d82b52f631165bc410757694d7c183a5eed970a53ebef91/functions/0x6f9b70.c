
undefined4 * FUN_006f9b70(int param_1)

{
  double dVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  int local_10;
  int iStack_c;
  
  if (param_1 - 1U < *(uint *)(unaff_ESI + 0x1c)) {
    return (undefined4 *)(*(int *)(unaff_ESI + 0xc) + -0x10 + param_1 * 0x10);
  }
  dVar1 = (double)param_1;
  if (dVar1 == 0.0) {
    puVar2 = *(undefined4 **)(unaff_ESI + 0x10);
  }
  else {
    iStack_c = (int)((ulonglong)dVar1 >> 0x20);
    local_10 = SUB84(dVar1,0);
    puVar2 = (undefined4 *)
             (((uint)(iStack_c + local_10) % ((1 << (*(byte *)(unaff_ESI + 7) & 0x1f)) - 1U | 1)) *
              0x20 + *(int *)(unaff_ESI + 0x10));
  }
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return &DAT_00c0bfc8;
    }
    if ((puVar2[6] == 3) && (dVar1 == *(double *)(puVar2 + 4))) break;
    puVar2 = (undefined4 *)puVar2[7];
  }
  return puVar2;
}

