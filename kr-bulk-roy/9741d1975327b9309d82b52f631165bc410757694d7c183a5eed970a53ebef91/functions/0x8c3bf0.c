
undefined4 FUN_008c3bf0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint in_EAX;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  undefined1 *local_c;
  byte *local_8;
  
  uVar1 = param_1[8];
  iVar2 = param_1[4];
  if (in_EAX < uVar1) {
    iVar3 = uVar1 * 2;
    local_c = (undefined1 *)(iVar2 + 0xe + in_EAX * 2);
    local_8 = (byte *)(iVar2 + 0x10 + (iVar3 + in_EAX) * 2);
    puVar5 = (undefined1 *)(iVar3 + 0x10 + in_EAX * 2 + iVar2);
    iVar6 = uVar1 * -2 + 1;
    puVar4 = (undefined1 *)(iVar2 + uVar1 * 6 + 0x10 + in_EAX * 2);
    do {
      param_1[0xb] = (uint)CONCAT11(*local_c,puVar5[1 - (iVar3 + 2)]);
      param_1[10] = (uint)CONCAT11(*puVar5,local_8[iVar6]);
      param_1[0xc] = (int)(short)((ushort)*local_8 << 8) | (uint)(byte)puVar4[iVar6];
      uVar7 = (uint)CONCAT11(*puVar4,puVar4[1]);
      if ((((uVar1 - 1 <= in_EAX) && (param_1[10] == 0xffff)) && (param_1[0xb] == 0xffff)) &&
         ((uVar7 != 0 &&
          ((undefined1 *)(*(int *)(*param_1 + 0x1f8) + *(int *)(*param_1 + 500)) <
           puVar4 + uVar7 + 2)))) {
        param_1[0xc] = 1;
LAB_008c3d08:
        param_1[9] = in_EAX;
        param_1[0xd] = 0;
        return 0;
      }
      if (uVar7 != 0xffff) {
        if (uVar7 != 0) {
          param_1[9] = in_EAX;
          param_1[0xd] = (int)(puVar4 + uVar7);
          return 0;
        }
        goto LAB_008c3d08;
      }
      local_c = local_c + 2;
      local_8 = local_8 + 2;
      in_EAX = in_EAX + 1;
      puVar5 = puVar5 + 2;
      puVar4 = puVar4 + 2;
    } while (in_EAX < uVar1);
  }
  return 0xffffffff;
}

