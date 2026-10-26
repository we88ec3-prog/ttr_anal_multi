
void FUN_007624f0(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 unaff_ESI;
  
  if ((in_ECX[9] != 0) &&
     (((piVar1 = *(int **)(in_ECX[9] + 0x165b4), piVar1 == (int *)0x0 ||
       (cVar3 = (**(code **)(*piVar1 + 0x1c))(), cVar3 != '\0')) && (in_ECX[0x3d] != 0)))) {
    if (*(int *)(in_ECX[9] + 0xfc) == 1) {
      FUN_00762800();
    }
    else if (*(int *)(in_ECX[9] + 0xfc) == 3) {
      FUN_007628f0();
    }
    iVar2 = in_ECX[9];
    if (((*(int *)(iVar2 + 0x3a0) == 1) || (*(int *)(iVar2 + 0x3a0) == 2)) ||
       ((*(int *)(iVar2 + 0x5a0) == 1 || (*(int *)(iVar2 + 0x5a0) == 2)))) {
      cVar3 = *(char *)((int)in_ECX + 0xca);
      if (cVar3 != '\0') {
        if (*(int *)(iVar2 + 0x3e4) == 1) {
          FUN_00762030(in_ECX);
          return;
        }
        if (cVar3 != '\0') {
          if (*(int *)(iVar2 + 1000) == 1) {
            FUN_00762170();
            return;
          }
          if ((cVar3 != '\0') && (*(int *)(iVar2 + 0x3e0) == 1)) {
            FUN_00762030(in_ECX);
            cVar3 = (**(code **)(*in_ECX + 0x1b0))(unaff_ESI);
            if (cVar3 != '\0') {
              puVar4 = (undefined4 *)FUN_00891268(0x14);
              if (puVar4 != (undefined4 *)0x0) {
                *puVar4 = FoxUI::FXUIEvent::vftable;
                puVar4[1] = 0xffffffff;
                puVar4[2] = 0xffffffff;
                puVar4[3] = 0;
                puVar4[4] = 0x3ec;
              }
              FUN_00748900();
            }
            in_ECX[0x58] = in_ECX[0x53];
            in_ECX[0x59] = in_ECX[0x53];
            FUN_00761800();
            return;
          }
        }
      }
      if (*(int *)(iVar2 + 0x3a4) == 1) {
        FUN_00761fe0();
        return;
      }
    }
  }
  return;
}

