
undefined4 FUN_0049d770(uint *param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  uint uVar8;
  int in_ECX;
  ushort *puVar9;
  bool bVar10;
  
  puVar4 = param_2;
  iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (iVar5 != 0) {
    uVar2 = *(undefined4 *)(iVar5 + 0x9c);
    iVar5 = FUN_0040f060();
    param_2 = (ushort *)uVar2;
    FUN_008438c0(&param_2);
    if (((in_ECX != *(int *)(iVar5 + 0x1c)) && (*(int *)(in_ECX + 0x10) != 0)) &&
       (4 < *(byte *)(*(int *)(in_ECX + 0x10) + 0x20))) {
      iVar5 = 0;
      do {
        puVar6 = (ushort *)(&PTR_DAT_00f7dde4)[iVar5];
        puVar9 = puVar4;
        do {
          uVar1 = *puVar6;
          bVar10 = uVar1 < *puVar9;
          if (uVar1 != *puVar9) {
LAB_0049d7f6:
            iVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
            goto LAB_0049d7fb;
          }
          if (uVar1 == 0) break;
          uVar1 = puVar6[1];
          bVar10 = uVar1 < puVar9[1];
          if (uVar1 != puVar9[1]) goto LAB_0049d7f6;
          puVar6 = puVar6 + 2;
          puVar9 = puVar9 + 2;
        } while (uVar1 != 0);
        iVar7 = 0;
LAB_0049d7fb:
        if (iVar7 == 0) {
          uVar8 = 1 << ((byte)iVar5 & 0x1f);
          uVar3 = *param_1;
          if ((uVar8 & uVar3) != 0) {
            *param_1 = ~uVar8 & uVar3;
            return 1;
          }
          *param_1 = uVar3 | uVar8;
          return 1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
    }
  }
  return 0;
}

