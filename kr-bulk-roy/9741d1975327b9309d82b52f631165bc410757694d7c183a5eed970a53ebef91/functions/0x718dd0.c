
void FUN_00718dd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int *piVar2;
  
  *in_ECX = Package::CFileScanner::vftable;
  piVar2 = *(int **)in_ECX[2];
  if (piVar2 != (int *)in_ECX[2]) {
    do {
      puVar1 = (undefined4 *)piVar2[9];
      if (puVar1 != (undefined4 *)0x0) {
        if (0xf < (uint)puVar1[0xc]) {
          FUN_0089120c(puVar1[7]);
        }
        puVar1[0xc] = 0xf;
        puVar1[0xb] = 0;
        *(undefined1 *)(puVar1 + 7) = 0;
        if (0xf < (uint)puVar1[5]) {
          FUN_0089120c(*puVar1);
        }
        puVar1[5] = 0xf;
        puVar1[4] = 0;
        *(undefined1 *)puVar1 = 0;
        FUN_0089120c(puVar1);
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)in_ECX[2]);
  }
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5]);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  FUN_00552640(in_ECX + 2);
  FUN_0089120c(in_ECX[2]);
  return;
}

