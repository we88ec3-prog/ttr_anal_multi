
void FUN_007b77c0(float param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  undefined4 uVar5;
  int *piVar6;
  int unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if (0 < *(int *)(unaff_EDI + 0x428)) {
    piVar6 = (int *)(unaff_EDI + 0x28);
    do {
      iVar2 = *piVar6;
      fVar4 = *(float *)(iVar2 + 0x20) + param_1 * 30.0;
      *(float *)(iVar2 + 0x20) = fVar4;
      if (*(float *)(iVar2 + 0x24) < fVar4 == (*(float *)(iVar2 + 0x24) == fVar4)) {
        iVar3 = **(int **)(iVar2 + 8);
        uVar5 = FUN_008fed10();
        (**(code **)(iVar3 + 0x1c))(uVar5);
        FUN_00780150(*(int *)(iVar2 + 8),*(undefined4 *)(*(int *)(iVar2 + 8) + 0x30));
      }
      else {
        iVar2 = *piVar6;
        if (*(undefined4 **)(iVar2 + 8) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(iVar2 + 8))(1);
          *(undefined4 *)(iVar2 + 8) = 0;
        }
        piVar1 = (int *)(*(int *)(iVar2 + 4) + 8);
        *piVar1 = *piVar1 + -1;
        FUN_00804260(piVar6);
        *piVar6 = *(int *)(unaff_EDI + 0x24 + *(int *)(unaff_EDI + 0x428) * 4);
        *(undefined4 *)(unaff_EDI + 0x24 + *(int *)(unaff_EDI + 0x428) * 4) = 0;
        *(int *)(unaff_EDI + 0x428) = *(int *)(unaff_EDI + 0x428) + -1;
      }
      local_8 = local_8 + 1;
      piVar6 = piVar6 + 1;
    } while (local_8 < *(int *)(unaff_EDI + 0x428));
  }
  return;
}

