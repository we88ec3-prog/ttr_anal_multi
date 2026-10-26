
void FUN_00761800(void)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *unaff_ESI;
  int iVar6;
  undefined1 local_10 [4];
  uint local_c;
  int *local_8;
  
  if (unaff_ESI[0x3d] != 0) {
    iVar3 = unaff_ESI[0x59];
    iVar6 = unaff_ESI[0x58];
    if (iVar6 != iVar3) {
      piVar5 = (int *)iVar6;
      if ((iVar6 < iVar3) || (piVar5 = (int *)iVar3, iVar6 <= iVar3)) {
        iVar6 = iVar3;
      }
      if ((int)piVar5 < unaff_ESI[0x5a]) {
        piVar5 = (int *)unaff_ESI[0x5a];
      }
      iVar6 = iVar6 - (int)piVar5;
      local_8 = piVar5;
      if (unaff_ESI[0x57] != 0) {
        FUN_00891d3d(unaff_ESI[0x57]);
        unaff_ESI[0x57] = 0;
      }
      lVar2 = (ulonglong)(iVar6 + 1) * 2;
      iVar3 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar2 >> 0x20) != 0) | (uint)lVar2);
      unaff_ESI[0x57] = iVar3;
      iVar3 = 0;
      if (0 < iVar6) {
        iVar4 = (int)piVar5 * 2;
        do {
          piVar5 = unaff_ESI + 0x42;
          if (7 < (uint)unaff_ESI[0x47]) {
            piVar5 = (int *)*piVar5;
          }
          *(undefined2 *)(unaff_ESI[0x57] + iVar3 * 2) = *(undefined2 *)(iVar4 + (int)piVar5);
          iVar3 = iVar3 + 1;
          iVar4 = iVar4 + 2;
          piVar5 = local_8;
        } while (iVar3 < iVar6);
      }
      *(undefined2 *)(unaff_ESI[0x57] + iVar6 * 2) = 0;
      uVar1 = unaff_ESI[0x5a];
      local_c = uVar1;
      if ((uint)unaff_ESI[0x46] < uVar1) {
        local_c = unaff_ESI[0x46] - 1;
      }
      local_8 = unaff_ESI + 0x42;
      if (7 < (uint)unaff_ESI[0x47]) {
        local_8 = (int *)*local_8;
      }
      (**(code **)(*(int *)unaff_ESI[0x3d] + 0x30))
                (unaff_ESI + 0x55,local_10,(int)local_8 + local_c * 2,(int)piVar5 - uVar1);
      (**(code **)(*(int *)unaff_ESI[0x3d] + 0x30))(unaff_ESI + 0x56,local_10,unaff_ESI[0x57],iVar6)
      ;
      (**(code **)(*unaff_ESI + 200))();
      return;
    }
    unaff_ESI[0x55] = 0;
    unaff_ESI[0x56] = 0;
    if (unaff_ESI[0x57] != 0) {
      FUN_00891d3d(unaff_ESI[0x57]);
      unaff_ESI[0x57] = 0;
    }
  }
  (**(code **)(*unaff_ESI + 200))();
  return;
}

