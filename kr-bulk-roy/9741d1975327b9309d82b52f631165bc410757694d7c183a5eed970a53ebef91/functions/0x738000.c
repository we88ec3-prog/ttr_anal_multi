
void FUN_00738000(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  D3DXCreateTextureFromFileInMemoryEx
            (*(undefined4 *)(in_ECX + 4),param_1,param_2,*(undefined4 *)(in_ECX + 8),
             *(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
             *(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),
             *(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20),
             *(undefined4 *)(in_ECX + 0x24),*(undefined4 *)(in_ECX + 0x28),
             *(undefined4 *)(in_ECX + 0x2c),*(undefined4 *)(in_ECX + 0x30),
             *(undefined4 *)(in_ECX + 0x34));
  return;
}

