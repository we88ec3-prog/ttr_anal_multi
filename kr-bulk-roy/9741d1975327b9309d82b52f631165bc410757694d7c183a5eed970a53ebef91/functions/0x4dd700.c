
undefined4 FUN_004dd700(void)

{
  undefined4 *in_ECX;
  undefined4 extraout_ECX;
  
  *in_ECX = CGameInfo::vftable;
  in_ECX[0x17ab] = 0;
  in_ECX[0x17ac] = 0;
  *(undefined2 *)(in_ECX + 0x17ad) = 0;
  in_ECX[0x17ae] = 0;
  in_ECX[0x17af] = 0;
  in_ECX[0x17b0] = 0;
  in_ECX[0x17b2] = 0;
  in_ECX[0x17b3] = 0;
  in_ECX[0x17b4] = 0;
  in_ECX[0x17b6] = 0;
  in_ECX[0x17b7] = 0;
  in_ECX[0x17b8] = 0;
  in_ECX[0x17ba] = 0;
  in_ECX[0x17bb] = 0;
  in_ECX[0x17bc] = 0;
  in_ECX[0x17be] = 0;
  in_ECX[0x17bf] = 0;
  in_ECX[0x17c0] = 0;
  in_ECX[0x17c1] = 0;
  in_ECX[0x17c3] = 0;
  in_ECX[0x17c4] = 0;
  in_ECX[0x17c5] = 0;
  in_ECX[0x17c6] = 0;
  in_ECX[0x17c7] = 0;
  in_ECX[0x17c8] = 0;
  FUN_004dd8f0();
  return extraout_ECX;
}

