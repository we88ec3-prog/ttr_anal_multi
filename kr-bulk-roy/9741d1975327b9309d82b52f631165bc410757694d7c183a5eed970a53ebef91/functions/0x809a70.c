
void FUN_00809a70(void)

{
  undefined1 uVar1;
  undefined2 *puVar2;
  undefined4 *in_ECX;
  uint uVar3;
  undefined4 local_48 [15];
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_48[0xe] = *in_ECX;
  local_c = in_ECX[1];
  FUN_008098e0(&DAT_00d63a00);
  uVar3 = 0;
  puVar2 = (undefined2 *)((int)in_ECX + 0x1a);
  do {
    uVar1 = *(undefined1 *)(puVar2 + 2);
    local_48[uVar3] =
         CONCAT31(CONCAT21(*puVar2,*(undefined1 *)((int)puVar2 + -1)),*(undefined1 *)(puVar2 + -1));
    local_48[uVar3 + 1] =
         CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((int)puVar2 + 5),uVar1),
                           *(undefined1 *)((int)puVar2 + 3)),*(undefined1 *)(puVar2 + 1));
    uVar3 = uVar3 + 2;
    puVar2 = puVar2 + 4;
  } while (uVar3 < 0xe);
  FUN_00809ba0(in_ECX + 2);
  *(undefined1 *)(in_ECX + 0x16) = *(undefined1 *)(in_ECX + 2);
  *(undefined1 *)((int)in_ECX + 0x59) = *(undefined1 *)((int)in_ECX + 9);
  *(undefined1 *)((int)in_ECX + 0x5a) = *(undefined1 *)((int)in_ECX + 10);
  *(undefined1 *)((int)in_ECX + 0x5b) = *(undefined1 *)((int)in_ECX + 0xb);
  *(undefined1 *)(in_ECX + 0x17) = *(undefined1 *)(in_ECX + 3);
  *(undefined1 *)((int)in_ECX + 0x5d) = *(undefined1 *)((int)in_ECX + 0xd);
  *(undefined1 *)((int)in_ECX + 0x5e) = *(undefined1 *)((int)in_ECX + 0xe);
  *(undefined1 *)((int)in_ECX + 0x5f) = *(undefined1 *)((int)in_ECX + 0xf);
  *(undefined1 *)(in_ECX + 0x18) = *(undefined1 *)(in_ECX + 4);
  *(undefined1 *)((int)in_ECX + 0x61) = *(undefined1 *)((int)in_ECX + 0x11);
  *(undefined1 *)((int)in_ECX + 0x62) = *(undefined1 *)((int)in_ECX + 0x12);
  *(undefined1 *)((int)in_ECX + 99) = *(undefined1 *)((int)in_ECX + 0x13);
  *(undefined1 *)(in_ECX + 0x19) = *(undefined1 *)(in_ECX + 5);
  *(undefined1 *)((int)in_ECX + 0x65) = *(undefined1 *)((int)in_ECX + 0x15);
  *(undefined1 *)((int)in_ECX + 0x66) = *(undefined1 *)((int)in_ECX + 0x16);
  *(undefined1 *)((int)in_ECX + 0x67) = *(undefined1 *)((int)in_ECX + 0x17);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

