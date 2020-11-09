# card
Generates card for all your cURLable needs.

# configuration
You can configure this program via `config.h` file. Example config with all customizastions is `config.def.h`. To apply changes run `make` and `make install` if you want to use this program globally

# setup cURLable card
simply write output of command to text file
```sh
card > curable-card
```
Copy to location, where HTTP server hosts. To read your card via cURL:
```sh
curl -sL your.webiste/curable-card
```

