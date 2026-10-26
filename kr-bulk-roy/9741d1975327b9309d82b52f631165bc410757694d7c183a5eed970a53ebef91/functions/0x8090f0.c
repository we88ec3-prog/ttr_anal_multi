
undefined4 FUN_008090f0(void)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  char *_Str1;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  (**(code **)(*in_EAX + 0x14))();
  piVar1 = (int *)FUN_0072e2e0(&DAT_00c517c8);
joined_r0x00809112:
  do {
    if (piVar1 == (int *)0x0) {
      return 1;
    }
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    for (iVar5 = *(int *)(iVar2 + 0x94); iVar5 != iVar2 + 0x44; iVar5 = *(int *)(iVar5 + 0x50)) {
      _Str1 = (char *)(iVar5 + 0x14);
      if (0xf < *(uint *)(iVar5 + 0x28)) {
        _Str1 = *(char **)_Str1;
      }
      iVar3 = __stricmp(_Str1,"name");
      if (iVar3 == 0) {
        if (iVar5 == 0) break;
        puVar6 = (undefined4 *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          puVar6 = (undefined4 *)*puVar6;
        }
        if (puVar6 == (undefined4 *)0x0) break;
        piVar4 = (int *)FUN_00809700();
        if (piVar4 != (int *)0x0) {
          iVar5 = (**(code **)(*piVar4 + 8))(piVar1);
          if (iVar5 != 0) {
            FUN_007bb350();
            break;
          }
          (**(code **)*piVar4)(1);
        }
        return 0;
      }
    }
    for (piVar1 = (int *)piVar1[0x10]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
      piVar4 = piVar1 + 8;
      if (0xf < (uint)piVar1[0xd]) {
        piVar4 = (int *)*piVar4;
      }
      iVar5 = __stricmp((char *)piVar4,"CMD");
      if (iVar5 == 0) goto joined_r0x00809112;
    }
    piVar1 = (int *)0x0;
  } while( true );
}

