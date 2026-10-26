
void FUN_0078d9d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *unaff_EDI;
  
  puVar6 = unaff_EDI;
  if (unaff_EDI != param_1) {
    while (puVar6 = puVar6 + 4, puVar6 != param_1) {
      iVar4 = puVar6[2];
      uVar3 = puVar6[1];
      uVar5 = puVar6[3];
      if (iVar4 < (int)unaff_EDI[2]) {
        if (unaff_EDI != puVar6) {
          puVar7 = puVar6 + 6;
          do {
            puVar7[-5] = puVar7[-9];
            puVar7[-4] = puVar7[-8];
            puVar7[-3] = puVar7[-7];
            puVar1 = puVar7 + -10;
            puVar7 = puVar7 + -4;
          } while (puVar1 != unaff_EDI);
        }
        unaff_EDI[2] = iVar4;
        unaff_EDI[1] = uVar3;
        unaff_EDI[3] = uVar5;
      }
      else {
        iVar2 = puVar6[-2];
        puVar7 = puVar6;
        while (iVar4 < iVar2) {
          puVar7[1] = puVar7[-3];
          puVar7[2] = puVar7[-2];
          puVar7[3] = puVar7[-1];
          iVar2 = puVar7[-6];
          puVar7 = puVar7 + -4;
        }
        puVar7[2] = iVar4;
        puVar7[1] = uVar3;
        puVar7[3] = uVar5;
      }
    }
  }
  return;
}

