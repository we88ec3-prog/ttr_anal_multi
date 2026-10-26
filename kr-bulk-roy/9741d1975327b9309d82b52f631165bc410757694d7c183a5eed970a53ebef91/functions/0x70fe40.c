
void FUN_0070fe40(void)

{
  int *piVar1;
  bool bVar2;
  int *in_EAX;
  int iVar3;
  int in_ECX;
  int unaff_EDI;
  
  piVar1 = *(int **)(in_ECX + 0x30);
  iVar3 = piVar1[9];
  bVar2 = false;
  if (in_EAX != (int *)0x0) {
    do {
      if (in_EAX[2] == 9) {
        if (in_EAX[4] == *(int *)(unaff_EDI + 8)) {
          bVar2 = true;
          in_EAX[4] = iVar3;
        }
        if (in_EAX[5] == *(int *)(unaff_EDI + 8)) {
          bVar2 = true;
          in_EAX[5] = iVar3;
        }
      }
      in_EAX = (int *)*in_EAX;
    } while (in_EAX != (int *)0x0);
    if (bVar2) {
      FUN_00713370((*(int *)(unaff_EDI + 8) << 0x11 | piVar1[9]) << 6,*(undefined4 *)(piVar1[3] + 8)
                  );
      iVar3 = piVar1[9] + 1;
      if ((int)(uint)*(byte *)(*piVar1 + 0x4b) < iVar3) {
        if (0xf9 < iVar3) {
                    /* WARNING: Subroutine does not return */
          FUN_006ff130(piVar1[3],"function or expression too complex",
                       *(undefined4 *)(piVar1[3] + 0x10));
        }
        *(char *)(*piVar1 + 0x4b) = (char)iVar3;
      }
      piVar1[9] = piVar1[9] + 1;
    }
  }
  return;
}

