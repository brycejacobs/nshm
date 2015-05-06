{
    "targets": [
        {
            "target_name": "nshm",
            "sources": [ "src/nshm.cpp"],
            "include_dirs": [
                "<!(node -e \"require('nan')\")"
            ]
        }
    ]
}