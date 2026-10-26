
void FUN_006ccfc0(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  iVar3 = FUN_006cdb80();
  if (iVar3 != 0) {
    iVar3 = FUN_006ce6f0(in_EAX);
    if ((iVar3 == 0) || (*(int *)(in_EAX + 0xdc) == 0)) {
      uVar4 = FUN_006cda20();
      FUN_006ce5a0(uVar4);
      FUN_006cde10();
    }
    else {
      iVar3 = FUN_00407ef0();
      if ((iVar3 != 0) && (iVar3 = FUN_006cda20(), iVar3 != 0)) {
        FUN_0043ff70(in_EAX + 0xb0);
        *(undefined4 *)(in_EAX + 0xd0) = *(undefined4 *)(iVar3 + 0x3c);
        *(undefined4 *)(in_EAX + 0xcc) = *(undefined4 *)(iVar3 + 0x38);
        FUN_006ceea0(iVar3 + 0x50);
        FUN_006ceea0(iVar3 + 0x60);
        FUN_006ceea0(iVar3 + 0x70);
        piVar1 = *(int **)(in_EAX + 0xd8);
        piVar2 = (int *)*piVar1;
        while (piVar2 != piVar1) {
          if (piVar2[5] == 0x26) {
            puVar5 = (undefined4 *)FUN_006ceed0();
            *puVar5 = piVar2[4];
            puVar5[1] = piVar2[5];
            break;
          }
          FUN_00406870();
          piVar1 = *(int **)(in_EAX + 0xd8);
        }
      }
    }
  }
  uVar4 = FUN_006cda20();
  *(undefined4 *)(in_EAX + 0x10) = uVar4;
  return;
}

