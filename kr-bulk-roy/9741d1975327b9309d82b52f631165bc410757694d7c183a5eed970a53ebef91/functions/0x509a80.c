
undefined4 FUN_00509a80(int param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  ushort *in_EAX;
  uint uVar5;
  uint *puVar6;
  undefined4 *puVar7;
  uint in_ECX;
  ushort *puVar8;
  
  uVar5 = (uint)(byte)in_EAX[1];
  if ((uVar5 - 1 < 0xf) && (param_1 = uVar5 * 0x108 + param_1, param_1 != 0)) {
    uVar1 = *(undefined2 *)((int)in_EAX + 3);
    *(undefined1 *)(param_1 + 0x102) = *(undefined1 *)((int)in_EAX + 5);
    *(undefined2 *)(param_1 + 0x100) = uVar1;
    if (in_ECX < 6) {
      uVar5 = 0;
    }
    else {
      uVar5 = (in_ECX - 6) / 0xf;
    }
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      puVar8 = (ushort *)((int)in_EAX + 0xf);
      if (*puVar8 == 0) {
        if ((byte)in_EAX[3] - 1 < 0xf) {
          puVar7 = (undefined4 *)((uint)(byte)in_EAX[3] * 0x10 + param_1);
          *puVar7 = 0;
          puVar7[1] = 0;
          puVar7[2] = 0;
          puVar7[3] = 0;
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0);
        }
      }
      else {
        uVar3 = *(uint *)((int)in_EAX + 0xb);
        uVar4 = *(uint *)((int)in_EAX + 7);
        if ((byte)in_EAX[3] - 1 < 0xf) {
          uVar2 = *puVar8;
          puVar6 = (uint *)((uint)(byte)in_EAX[3] * 0x10 + param_1);
          puVar6[1] = *(uint *)((int)in_EAX + 0x11);
          *puVar6 = (uint)uVar2;
          puVar6[2] = uVar4;
          puVar6[3] = uVar3;
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0);
        }
      }
      in_EAX = puVar8;
    }
    return 0;
  }
  FUN_006edb60("EqSt: Invalid character idx %d",uVar5);
  return 0x80004005;
}

