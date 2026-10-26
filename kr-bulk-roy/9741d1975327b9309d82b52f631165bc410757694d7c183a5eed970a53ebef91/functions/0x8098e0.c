
void FUN_008098e0(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint in_ECX;
  uint uVar6;
  uint *unaff_ESI;
  uint local_48 [17];
  
  local_48[0x10] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar3 = *unaff_ESI;
  uVar6 = uVar3 + in_ECX * 8;
  uVar4 = uVar3 >> 3 & 0x3f;
  if (uVar6 < uVar3) {
    unaff_ESI[1] = unaff_ESI[1] + 1;
  }
  unaff_ESI[1] = unaff_ESI[1] + (in_ECX >> 0x1d);
  *unaff_ESI = uVar6;
  while (in_ECX != 0) {
    *(undefined1 *)((int)unaff_ESI + uVar4 + 0x18) = *param_1;
    uVar4 = uVar4 + 1;
    param_1 = param_1 + 1;
    in_ECX = in_ECX - 1;
    if (uVar4 == 0x40) {
      puVar5 = (undefined2 *)((int)unaff_ESI + 0x1a);
      uVar6 = 0;
      do {
        uVar1 = *(undefined1 *)(puVar5 + 2);
        local_48[uVar6] =
             CONCAT31(CONCAT21(*puVar5,*(undefined1 *)((int)puVar5 + -1)),
                      *(undefined1 *)(puVar5 + -1));
        uVar2 = *(undefined1 *)(puVar5 + 4);
        local_48[uVar6 + 1] =
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)puVar5 + 5),uVar1),
                               *(undefined1 *)((int)puVar5 + 3)),*(undefined1 *)(puVar5 + 1));
        uVar1 = *(undefined1 *)(puVar5 + 6);
        local_48[uVar6 + 2] =
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)puVar5 + 9),uVar2),
                               *(undefined1 *)((int)puVar5 + 7)),*(undefined1 *)(puVar5 + 3));
        local_48[uVar6 + 3] =
             CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)puVar5 + 0xd),uVar1),
                               *(undefined1 *)((int)puVar5 + 0xb)),*(undefined1 *)(puVar5 + 5));
        uVar6 = uVar6 + 4;
        puVar5 = puVar5 + 8;
      } while (uVar6 < 0x10);
      FUN_00809ba0(unaff_ESI + 2);
      uVar4 = 0;
    }
  }
  __security_check_cookie(local_48[0x10] ^ (uint)&stack0xfffffffc);
  return;
}

