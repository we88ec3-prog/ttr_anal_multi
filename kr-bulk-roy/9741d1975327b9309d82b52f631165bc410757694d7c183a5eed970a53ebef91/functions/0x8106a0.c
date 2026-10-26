
undefined4 FUN_008106a0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  alSource3i(*(undefined4 *)(in_ECX + 0x10),0x20006,param_2,param_1,0);
  alGetError();
  FUN_00810080();
  return 1;
}

