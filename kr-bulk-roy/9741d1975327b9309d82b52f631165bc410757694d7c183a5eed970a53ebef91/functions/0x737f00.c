
void FUN_00737f00(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  D3DXCreateTextureFromFileInMemoryEx
            (*(undefined4 *)(in_ECX + 4),param_1,param_2,0xffffffff,0xffffffff,DAT_00fba824,0,0,1,
             0xffffffff,0xffffffff,0,0,0,*(undefined4 *)(in_ECX + 8));
  return;
}

