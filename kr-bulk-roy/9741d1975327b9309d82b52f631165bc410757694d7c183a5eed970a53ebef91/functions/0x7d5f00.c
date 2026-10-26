
void FUN_007d5f00(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  int local_c;
  int local_8;
  
  *unaff_EDI = IS3D::CFaceInfo::vftable;
  unaff_EDI[3] = unaff_ESI;
  if (*(int **)(unaff_ESI + 0x74) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x74) + 0x24))();
    if (iVar2 == 0) {
      uVar3 = *(undefined4 *)(unaff_ESI + 0x74);
      goto LAB_007d5f44;
    }
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x74) + 0x38))();
    if (0 < iVar2) {
      uVar3 = (**(code **)(**(int **)(unaff_ESI + 0x74) + 0x28))(0);
      goto LAB_007d5f44;
    }
  }
  uVar3 = 0;
LAB_007d5f44:
  unaff_EDI[4] = uVar3;
  local_c = 0;
  local_8 = 0;
  FUN_007c5f40(uVar3,&local_c);
  uVar4 = local_8 - local_c >> 0x1f;
  fVar1 = (float)(int)((local_8 - local_c ^ uVar4) - uVar4);
  unaff_EDI[1] = fVar1;
  if (fVar1 < 1.0) {
    unaff_EDI[2] = 1;
    unaff_EDI[1] = 0x42b40000;
  }
  return;
}

